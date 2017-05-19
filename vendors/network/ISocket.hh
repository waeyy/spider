//
// ISocket.hh for  in /home/soidik_d/Semestre_05/cpp/Spider/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Nov  1 17:41:22 2015 SOIDIKI Djamil
// Last update Mon Nov  2 01:17:40 2015 SOIDIKI Djamil
//

#ifndef		_ISOCKET_HH_
# define	_ISOCKET_HH_

#include	"IHandler.hh"

class		ISocket {

public:
  virtual ~ISocket() = default;

  virtual void	bind() = 0;
  virtual void  listen() = 0;
  virtual void	async_accept() = 0;

  virtual void	poll() = 0;
  virtual void	run() = 0;
  virtual void	stop() = 0;
};

#endif		/* _ISOCKET_HH_ */
