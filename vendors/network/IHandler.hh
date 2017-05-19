//
// IHandler.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Nov  1 19:40:58 2015 SOIDIKI Djamil
// Last update Wed Nov 18 01:01:17 2015 SOIDIKI Djamil
//

#ifndef		_IHANDLER_HH_
# define	_IHANDLER_HH_

#include	<boost/asio.hpp>
#include	"../exception/Exception.hh"

using		boost::asio::ip::tcp;

class		IHandler {

public:
  virtual ~IHandler() = default;

  virtual int	write(const std::string& msg, int size) = 0;
  virtual int	read(int size) = 0;
  virtual void	async_write(const std::string& msg, int size) = 0;
  virtual void	async_read(int size) = 0;
  virtual void	run() = 0;
  virtual std::string getId() = 0;
};

#endif		/* _IHANDLER_HH_ */
