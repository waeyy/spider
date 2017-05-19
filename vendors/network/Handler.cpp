//
// Handler.cpp for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Nov  1 20:26:48 2015 SOIDIKI Djamil
// Last update Wed Nov 18 10:11:28 2015 SOIDIKI Djamil
//

#include	"Handler.hh"

Handler::Handler(const boost::shared_ptr<ISSL>& ssl,
		 boost::asio::io_service& ios) :
  _socket(ios, ssl->getContext()), 
  _timer(ios, boost::posix_time::millisec(5000))
{
}

Handler::~Handler()
{
}

int		Handler::write(const std::string& msg, int size)
{
  (void) msg;
  (void) size;
  return (0);
}

int		Handler::read(int size) 
{
  (void) size;
  return (0);
}

void		Handler::async_write(const std::string& msg, int size)
{
  (void) msg;
  (void) size;

   boost::asio::async_write(this->_socket,
			   boost::asio::buffer(msg),
			   boost::bind(&Handler::writeCallback,
				       shared_from_this(),
				       boost::asio::placeholders::error)
				       );
}

void		Handler::async_read(int size)
{
  (void) size;
}

ssl_socket::lowest_layer_type&	Handler::getSocket()
{
  return (this->_socket.lowest_layer());
}

void		Handler::run()
{
  std::cout << "run" << std::endl;

  this->_id = this->getSocket().remote_endpoint().address().to_string();

  std::cout << this->_id << std::endl;
  this->_log = std::string("logs/" + this->_id + ".log");

  this->_clients.push_back(shared_from_this());
  this->_socket.async_handshake(boost::asio::ssl::stream_base::server,
  				boost::bind(&Handler::handshakeCallback, 
  					    shared_from_this(),
  					    boost::asio::placeholders::error));
}

void		Handler::handshakeCallback(const boost::system::error_code& e)
{
  std::cout << "-- handshakeCallback --" << std::endl;
  if (!e)
    {
      this->_socket.async_read_some(boost::asio::buffer(this->_data, 1024),
				    boost::bind(&Handler::readCallback, 
						shared_from_this(),
						boost::asio::placeholders::error,
						boost::asio::placeholders::bytes_transferred));

      //      this->postCheckPing();
    }
  else
    std::cout << e.message() << std::endl;
}

void		Handler::listClients()
{
  std::string	msg;
  std::cout << "-- listClients --" << std::endl;
  for(auto b = this->_clients.begin(), e = this->_clients.end(); b
        != e; ++b)
    msg += (*b)->getId() + " ";
  std::cout << msg << std::endl;
}

void		Handler::readCallback(const boost::system::error_code& error,
				      size_t bytes_transferred)
{
  std::cout << "-- readCallback --" << std::endl;
  if (!error)
    {
      std::cout << "info lu: " << this->_data << std::endl;
      // std::string tmp(this->_data);
      // if (tmp.find("clients") == 0)
      // 	this->listClients();
      std::ofstream file("logs/" + this->_id + ".log", std::ios::out | 
			 std::ios_base::app); 

      if (file)
	file << this->_data;

      boost::asio::async_write(this->_socket,
			       boost::asio::buffer(this->_data, 
						   bytes_transferred),
			       boost::bind(&Handler::writeCallback, 
					   shared_from_this(),
					   boost::asio::placeholders::error));

      //this->postCheckPing();
    }
}

void		Handler::writeCallback(const boost::system::error_code& error)
{
  if (!error)
    {
      this->_socket.async_read_some(boost::asio::buffer(this->_data, 1024),
				    boost::bind(&Handler::readCallback, 
						shared_from_this(),
						boost::asio::placeholders::error,
						boost::asio::placeholders::bytes_transferred));
    }
}

void		Handler::shutdownCallback(const boost::system::error_code& e)
{
  (void) e;
}

void		Handler::close()
{
  std::cout << "timed out" << std::endl;
  this->_socket.async_shutdown(boost::bind(&Handler::shutdownCallback,
					   shared_from_this(),
					   boost::asio::placeholders::error));
}

void		Handler::postCheckPing()
{
  this->_timer.expires_from_now(boost::posix_time::minutes(1)); 
  this->_timer.async_wait(boost::bind(&Handler::close, 
				      shared_from_this()));
}

std::string	Handler::getId()
{
  return (this->_id);
}
