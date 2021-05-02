import static org.lwjgl.glfw.GLFW.*;
import org.lwjgl.glfw.GLFWVidMode;
public class Main {

	public static void main(String[] args) {
		if(!glfwInit()) {
			throw new IllegalStateException("Failed");
		}
		glfwWindowHint(GLFW_VISIBLE,GLFW_FALSE);
		long window = glfwCreateWindow(640,480,"My simple program",0,0);
		if(window == 0) {
			throw new IllegalStateException("agfjsf");
			
		}
		GLFWVidMode video = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(window,(video.width()+640) / 2,(video.height() - 480)/2);
		glfwShowWindow(window);
		while(!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
		glfwTerminate();

	}

}
