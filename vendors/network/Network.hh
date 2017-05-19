//
// Network.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Oct 27 15:34:38 2015 SOIDIKI Djamil
// Last update Tue Nov  3 00:19:29 2015 SOIDIKI Djamil
//

#ifndef		_NETWORK_HH_
# define	_NETWORK_HH_

#include	<iostream>
#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	"Listener.hh"
#include	"Secure.hh"

class		Network {

private:
  boost::shared_ptr<ISSL>			_ssl;
  std::unique_ptr<ISocket>			_listener;
  bool						_shutdown;

private:
  Network(const Network& net);
  Network& operator=(const Network& net);

public:
  Network(const boost::shared_ptr<boost::asio::io_service>& ios = 
	  boost::shared_ptr<boost::asio::io_service>(new boost::asio::io_service()));
  virtual ~Network();

  void		poll();
  void		run();
  void		stop();

  bool		hasStopped();

private:
  void		accept();
  void		acceptCallback();
};

#endif		/* _NETWORK_HH_ */
