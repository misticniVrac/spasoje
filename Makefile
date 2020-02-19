#										*
#				TEMPORARY 		    			*
#										*


CC := g++

LIB :=  -lGLEW -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor 


src = $(wildcard src/*.cpp) $(wildcard src/graphics/*.cpp)
obj =  $(addprefix obj/, $(addsuffix .o, $(notdir $(basename $(src)))))

build:
	@mkdir -p  obj
	$(CC) -c ${src} 
	@mv *.o obj/
	$(CC)  ${obj} -o spasoje ${LIB}

clean:
	    rm -f $(obj) spasoje
