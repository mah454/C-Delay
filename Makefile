.PHONY: build clean

build : 
	mkdir -p build/empDir
	gcc src/main.c --static-pie -o build/main  
	strip build/main  
	(cd build/empDir ; tar -cvf ../empty.tar .)
	docker import build/empty.tar empty:latest
	docker build . -t renderer:latest

clean: 
	rm -rf build/
