import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import org.lwjgl.opengl.GL;
public class Main {

	public Main() {
		if(glfwInit() != true) {
			System.err.println("sdvjkdf");
			System.exit(1);
		}
		long win = glfwCreateWindow(640,480,"Color window",0,0);
		glfwShowWindow(win);
		glfwMakeContextCurrent(win);
		GL.createCapabilities();
		println("heyyorrr");
		while(glfwWindowShouldClose(win) != true) {
			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_QUADS);
			    glColor4f(1,0,0,0);
				glVertex2f(-0.5f,0.5f);
				
				glColor4f(0,1,0,1);
				glVertex2f(0.5f,0.5f);
				
				glColor4f(0,0,1,0);
				glVertex2f(0.5f,-0.5f);
				
				glColor4f(0,0,0,1);
				glVertex2f(-0.5f,-0.5f);
			glEnd();
			glfwSwapBuffers(win);
			
		}
		
		glfwTerminate();
		

	}
	private void println(String string) {
		// TODO Auto-generated method stub
		
	}
	public static void main(String[] args) {
		System.out.print(false);
		new Main();
		
	}

}
