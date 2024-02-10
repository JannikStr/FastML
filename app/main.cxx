#include <QtWidgets>
#include <iostream>
#include <qapplication.h>

#include "core/visualizer.hxx"

const int WINDOW_FACTOR = 80;

int main(int argc, char **argv) {
  QApplication application(argc, argv);
  VisualizerWidget visualizerWidget;
  visualizerWidget.resize(WINDOW_FACTOR * 16, WINDOW_FACTOR * 9);
  visualizerWidget.setWindowTitle(
      QApplication::translate("window-title", "FastML-Visualizer"));
  visualizerWidget.show();
  return application.exec();
}
