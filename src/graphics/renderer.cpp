#include "renderer.h"

#include <GL/glew.h>
#include <iostream>


#include "shader.h"
#include "../math/vector.h"
#include "../math/matrix.h"
#include "texture2d.h"

namespace spasoje{
namespace renderer{


GLuint 
genSprite()
{

	float vertices[] = {
  	 	//position		//color		//texture pos
	      1,  1, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   
	      1, -1, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   
	     -1, -1, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,   
	     -1,  1, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f  
	 };

	unsigned int VBO,VAO,EBO;

	    unsigned int indices[] = {  
		            0, 1, 3, // first triangle
			            1, 2, 3  // second triangle
					       };
	glGenVertexArrays(1,&VAO);

	glGenBuffers(1,&VBO);	

	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);


 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
	


	return VAO;


}
void
drawSprite(GLuint VAO, Shader &shader,Texture2D &texture, Vector2 position, Vector2 size, GLfloat rotation, Vector3 color)
{	

	shader.start();
	Matrix4 sprite = Matrix4::identity();
	       
		
	sprite = Matrix4::scale(sprite,Vector3(size,0));

	sprite = Matrix4::translate(sprite, Vector3(0*size.x, 0*size.y, 0.0f));
	sprite = Matrix4::rotate(sprite,rotation,Vector3(0.0,0.0,-1.0));	

      	sprite = Matrix4::translate(sprite,Vector3(position,0));
	
	Matrix4 projection = Matrix4::orthographic(0.0f,800.0,0,600,-1.0,1.0);//this needs to be updated on screen resize

	Matrix4 view = Matrix4::identity();	
	
	
	sprite.multiply(view);
	sprite.multiply(projection);

	shader.setMatrix4("sprite",sprite);
	
	glBindTexture(GL_TEXTURE_2D, texture.getID());

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
	glBindVertexArray(0);


}

}
}
