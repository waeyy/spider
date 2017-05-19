//
// Main.cpp for  in /home/soidik_d/Semestre_05/cpp/Spider/sources
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Oct 27 10:11:20 2015 SOIDIKI Djamil
// Last update Wed Nov 18 08:33:26 2015 SOIDIKI Djamil
//

#include	<iostream>
#include	"../vendors/exception/Exception.hh"
#include	"../vendors/network/Network.hh"

int		main()
{
  try
    {
      boost::asio::io_service	ios;

      Network			network;
  
      std::cout << "Spider Server" << std::endl;

      network.poll();
      network.run();
    }
  catch (const Exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  return (EXIT_SUCCESS);
}
