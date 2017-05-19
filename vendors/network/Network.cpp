//
// Network.cpp for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Oct 27 16:10:49 2015 SOIDIKI Djamil
// Last update Tue Nov  3 00:21:09 2015 SOIDIKI Djamil
//

#include	<boost/interprocess/detail/atomic.hpp>
#include	"Network.hh"

Network::Network(const boost::shared_ptr<boost::asio::io_service>& ios) : 
  _ssl(new Secure()), _listener(new Listener(_ssl, ios)), _shutdown(false)
{
  this->_listener->bind();
  this->_listener->listen();
  this->accept();
}

Network::~Network()
{
}

void		Network::poll()
{
  this->_listener->poll();
}

void		Network::run()
{
  this->_listener->run();
}

void		Network::stop()
{
  this->_shutdown = true;
  this->_listener->stop();
}

void		Network::accept()
{
  this->_listener->async_accept();
}

bool		Network::hasStopped()
{
  return (this->_shutdown);
}
