#include "Server.hpp"
#include "Connection.hpp"


#include <iostream>

#include <boost/bind.hpp>



namespace SP {

	Server::Server(boost::asio::io_service & ios, unsigned port, SyncBuffer<ImageConfig>& syncBuff, LightField& imgLF)
		: acc(ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), syncBufferRef(syncBuff), imgLightFieldRef(imgLF){
		startAccept();
	}


	void Server::startAccept() {

		std::cerr << "New connection" << std::endl;
		Connection::ConnectionPointer newConnection = Connection::createWithBuffer(acc.get_io_service(), syncBufferRef, imgLightFieldRef);

		//acc.accept(newConnection->getSocketRef());
		acc.async_accept(newConnection->getSocketRef(), std::bind(&Server::handleAccept, this, newConnection, std::placeholders::_1));
	}

	void Server::handleAccept(Connection::ConnectionPointer newConnection, const boost::system::error_code& err) {

		if (!err) {
			std::cerr << "Start connection" << std::endl;
			newConnection->start();
		} else {
			std::cerr << "Error:" << err << std::endl;

			//KAOCC: TODO: change the exception type
			throw std::runtime_error("Error in Async Accept");
		}


		// again !
		startAccept();
	}


}
