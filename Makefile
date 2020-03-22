#										*
#				TEMPORARY 		    			*
#										*


CC := g++


FT := -I/usr/include/freetype2 #location of freetype headers, change this 

C := gcc

LIB :=   src/lualib/lualib.a  -lGLEW -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -ldl -lfreetype 

lua = $(wildcard src/lualib/src/*.c) 
luao = $(wildcard src/lualib/obj/*)


src = $(wildcard src/*.cpp) $(wildcard src/graphics/*.cpp) $(wildcard src/math/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/lualib/*.c)


obj =  $(addprefix obj/, $(addsuffix .o, $(notdir $(basename $(src)))))

build:
	@mkdir -p  obj
	$(CC) -c ${src} ${FT}	
	@mv *.o obj/
	$(CC)  ${obj} -o spasoje ${LIB}

clean:
	    rm -f $(obj) spasoje


lua:
	$(C) -c ${lua}
	@mkdir -p src/lualib/obj
	@mv *.o src/lualib/obj
	@ar rcs src/lualib/lualib.a ${luao}
