#include <iostream>
#include <filesystem>
#include <string>

#include <FL/Fl_Window.H>

#include <libmultidraw/Catalog.hpp>
#include <libmultidraw/Creator.hpp>
#include <libmultidraw/Editor.hpp>
#include <libmultidraw/Multidraw.hpp>
#include <libmultidraw/Viewer.hpp>
#include <libmultidraw/version.hpp>

using namespace multidraw;
namespace fs = std::filesystem;

const int WIDTH = 800;
const int HEIGHT = 600;

class ExampleEditor : public Editor {
public:
  ExampleEditor(const std::string& initial_file);

  virtual Viewer* viewer(int index) const { return _viewer; };
  
private:
  Viewer* _viewer;
};

class ExampleCatalog : public Catalog {
public:
  ExampleCatalog(const std::string& name, Creator* creator);

  bool retrieve(const fs::path& source, Component*& comp);
};

class ExampleCreator : public Creator {
public:
  ExampleCreator();
};

ExampleEditor::ExampleEditor(const std::string& initial_file) :
  Editor(initial_file, "")
{
  Fl_Window* window = new Fl_Window(0, 0, WIDTH, HEIGHT, "MultidrawExample");

  _viewer = new Viewer(0, 0, WIDTH, HEIGHT, this);

  window->end();
  
  window->resizable(_viewer);
  
  this->window(window);
}// constructor

ExampleCatalog::ExampleCatalog(const std::string& name, Creator* creator) :
  Catalog(name, creator)
{
}// constructor

bool
ExampleCatalog::retrieve(const fs::path& source, Component*& comp)
{
  std::cout << "Ready to retrieve " << source.string() << std::endl;

  return false;
}// retrieve

ExampleCreator::ExampleCreator()
{
}// constructor

int main() {
  Multidraw* multidraw = Multidraw::instance();
  multidraw->catalog(
    new ExampleCatalog("MultidrawExample", new ExampleCreator())
  );
                     
  ExampleEditor* editor = new ExampleEditor("./metatooth.stl");

  multidraw->open(editor);
  std::cout << "libmultidraw-" <<  __version__ << std::endl;
  
  multidraw->run();

  delete multidraw;

  return 0;
}
