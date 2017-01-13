// Author: Xavier Corbillon
// IMT Atlantique
//
// Description:
// Pur virtual class used to interact with meshes such as MeshCube
#pragma once

// Library/third-party includes
#include <GL/glew.h>

// This must come after we include <GL/gl.h> so its pointer types are defined.
#include <osvr/RenderKit/GraphicsLibraryOpenGL.h>

//standard includes
#include <memory>
#include <vector>

namespace IMT
{

//Forward declaration
class ShaderTexture;

class Mesh
{
public:
  Mesh(void): m_initialized(false), m_vertexBufferId(0), m_uvBufferId(0),
      m_vertexArrayId(0), m_vertexBufferData(), m_uvBufferData() {}
  virtual ~Mesh(void);

  void Draw(const GLdouble projection[], const GLdouble modelView[], std::shared_ptr<ShaderTexture> shader);

  void Init(void);

  const auto& GetVertexBufferId(void) const {return m_vertexBufferId;}
  const auto& GetUvBufferId(void) const {return m_uvBufferId;}

  void AppendVertexBufferData(std::vector<GLfloat> const& newData) {m_vertexBufferData.insert(m_vertexBufferData.end(),
    newData.begin(), newData.end());}
  void AppendUvBufferData(std::vector<GLfloat> const& newData) {m_uvBufferData.insert(m_uvBufferData.end(),
    newData.begin(), newData.end());}

private:
  Mesh(const Mesh&) = delete;
  Mesh& operator=(const Mesh&) = delete;

  //Used to unit the vertexArray
  virtual void InitImpl(void) = 0;

  bool m_initialized = false;
  GLuint m_vertexBufferId = 0;
  GLuint m_uvBufferId = 0;
  GLuint m_vertexArrayId = 0;
  std::vector<GLfloat> m_vertexBufferData;
  std::vector<GLfloat> m_uvBufferData;
};
}
