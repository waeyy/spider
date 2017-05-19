//
// Handler.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Nov  1 19:50:07 2015 SOIDIKI Djamil
// Last update Thu Nov 19 22:00:15 2015 SOIDIKI Djamil
//

#ifndef		_HANDLER_HH_
# define	_HANDLER_HH_

#include	<fstream>
#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	<boost/lexical_cast.hpp>
#include        <boost/enable_shared_from_this.hpp>
//#include	"NetworkServices.hpp"
#include	"IHandler.hh"
#include	"ISSL.hh"

#define		MAX_TIMEOUT	5

using		boost::asio::ip::tcp;

class		Handler : public IHandler , public boost::enable_shared_from_this<Handler>{

public:
  typedef boost::shared_ptr<IHandler>	client_ptr;
  typedef std::vector<client_ptr>       array_clients;
  
private:
  ssl_socket			_socket;
  char				_data[1024];

  std::string			_id;
  boost::asio::deadline_timer   _timer;
  array_clients			_clients;
  std::string			_log;

public:
  Handler(const boost::shared_ptr<ISSL>& ssl,
	  boost::asio::io_service& ios);
  virtual ~Handler();

  int		write(const std::string& msg, int size);
  int		read(int size);
  void		async_write(const std::string& msg, int size);
  void		async_read(int size);

  ssl_socket::lowest_layer_type& getSocket();
  void		run();
  void		postCheckPing();
  void		listClients();
  std::string	getId();

private:
  void		writeCallback(const boost::system::error_code& e);
  void		readCallback(const boost::system::error_code& e, size_t bytes);
  void		handshakeCallback(const boost::system::error_code& e);

  void		shutdownCallback(const boost::system::error_code& e);

  void		close();
};

#endif		/* _HANDLER_HH_ */

