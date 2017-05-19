//
// Listener.cpp for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Nov  1 18:16:39 2015 SOIDIKI Djamil
// Last update Tue Nov  3 01:22:24 2015 SOIDIKI Djamil
//

#include	"Listener.hh"

Listener::Listener(const boost::shared_ptr<ISSL>& ssl,
		   const boost::shared_ptr<boost::asio::io_service>& ios) : 
  _ssl(ssl), _ios(ios), _acceptor(*_ios)
{
}

Listener::~Listener()
{
}

void		Listener::bind()
{
  tcp::endpoint	endpoint(tcp::v4(), _PORT_SERVER_);
 
 this->_acceptor.open(endpoint.protocol());
 this->_acceptor.set_option(tcp::acceptor::reuse_address(false));
 this->_acceptor.bind(endpoint);
}

void		Listener::listen()
{
  this->_acceptor.listen();
}

void		Listener::async_accept()
{
  auto handle = new Handler(this->_ssl, *(this->_ios));
  
  this->_acceptor.async_accept(handle->getSocket(),
			       boost::bind(&Listener::acceptCallback,
					   this,
					   boost::shared_ptr<IHandler>(handle),
					   boost::asio::placeholders::error)
			       );
}

void	Listener::acceptCallback(const boost::shared_ptr<IHandler>& hand,
				 const boost::system::error_code& error)
{
  if (!error)
    {
      std::cout << "Nouveau client" << std::endl;
      hand->run();
      this->async_accept();
    }
  else
    throw Exception(NO_ERRNO, 
		    __LINE__, 
		    __FILE__, 
		    "acceptCallback: Listener::async_accept() fail");
}

void		Listener::poll()
{
  this->_ios->poll();
}

void		Listener::run()
{
  this->_ios->run();
}

void		Listener::stop()
{
  this->_ios->stop();
}
