server:
	clang++  -o $@ -Llibuv/out/Debug/  src/HttpServer.cc main.cc -I ./ -luv -lpthread

clean:
	-rm -fv server
