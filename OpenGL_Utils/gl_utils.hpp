#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>

namespace wvxy {

class GlUtils {
  public:
    GlUtils(const std::string name, int screen_width, int screen_height);
    ~GlUtils();
    GlUtils(const GlUtils&) = delete;
    GlUtils& operator=(const GlUtils&) = delete;

    GLFWwindow* window;

    void Draw(std::vector<float>& vertices, std::vector<uint16_t>& indices);

    void Run();

  private:
    int SCR_WIDTH{800};
    int SCR_HEIGHT{600};
    const std::string windowName;

    unsigned int VBO, VAO, EBO;
    std::string vertexShaderSource;
    std::string fragmentShaderSource;
    unsigned int shaderProgram;

    void Init();
    GLFWwindow* InitGLFW();
    void InitGLAD();
    void InitViewport();

    std::string ReadShaderSource(const std::string path);
    unsigned int CompileShader(std::string& source, int type);
    unsigned int CreateProgram(unsigned int vertexShader,
                               unsigned int fragmentShader);

    void CreateBuffer(std::vector<float>& vertices, std::vector<uint16_t>& indices);
    void BindBuffer();


};
} // namespace wvxy
