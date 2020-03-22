#include "renderer.h"


#include <GLFW/glfw3.h>
#include <GL/glew.h>


#include "shader.h"
#include "../math/vector.h"
#include "../math/matrix.h"
#include "texture2d.h"

namespace spasoje{
namespace renderer{



Matrix4 projection;

static GLuint quadVAO = -1;

float 
fps()
{
	static float fps = 0.0f;
	static double lastTime = glfwGetTime();

	double currentTime = glfwGetTime();
	int frameCount;


	if(currentTime - lastTime >= 1.0)//second passed
	{
		fps = frameCount;
		frameCount = 0;
		lastTime = currentTime;
	}
	frameCount++;

	return fps;

	

}

GLuint 
genQuad()
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
drawSprite(Shader &shader,Texture2D &texture, Vector2 position, Vector2 size, GLfloat rotation, Vector3 color)
{	
	
	if(quadVAO==-1)
		quadVAO = genQuad();//@REFACTOR
	
	shader.start();
	Matrix4 sprite = Matrix4::identity();
	       
		
	sprite = Matrix4::scale(sprite,Vector3(size,0));

	sprite = Matrix4::translate(sprite, Vector3(0.0f, 0.0f, 0.0f));
	sprite = Matrix4::rotate(sprite,rotation,Vector3(0.0,0.0,-1.0));	

      	sprite = Matrix4::translate(sprite,Vector3(position,0));
	

	Matrix4 view = Matrix4::identity();	
	
	Matrix4 projection = getProjection();

	sprite.multiply(view);
	sprite.multiply(projection);

	shader.setMatrix4("sprite",sprite);
	shader.setVector3("textColor",color);


	glBindTexture(GL_TEXTURE_2D, texture.getID());

	glBindVertexArray(quadVAO);
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
	glBindVertexArray(0);


}


void drawText(Font font,std::string text,Shader shader,Vector2 position,float scale,Vector3 color)
{
	Texture2D c_texture;
	


	for(int i=0;i<text.size();i++)
	{

		char c = text[i];
		Character character = font.getCharacter(c);
 		
	        
		GLfloat w = character.Size.x * scale /2;
       	 	GLfloat h = character.Size.y * scale /2;
	
		GLfloat xpos = position.x + w + (character.Bearing.x * scale);
        	GLfloat ypos = position.y + h - ((character.Size.y - character.Bearing.y) * scale);


		c_texture.setID(character.texture_ID);	

		drawSprite(shader,c_texture,Vector2(xpos,ypos),Vector2(w,h),0,color);
        	
		position.x += (character.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)

	}
    	
	glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);

}
	
}
}
