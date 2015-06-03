server:
	clang++  -Llibuv/out/Debug/  src/HttpServer.cc main.cc -I ./ -luv -lpthread
