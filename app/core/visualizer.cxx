#include "visualizer.hxx"
#include <QtWidgets>

VisualizerWidget::VisualizerWidget(QWidget *parent)
    : QWidget(parent),
      trainPercentageSlider(new QSlider(Qt::Orientation::Horizontal)) {
  QGridLayout *mainLayout = new QGridLayout();
  trainPercentageSlider->setMinimum(0);
  trainPercentageSlider->setMaximum(100);
  trainPercentageSlider->setMaximumWidth(100);
  mainLayout->addWidget(trainPercentageSlider, 0, 0);
  setLayout(mainLayout);
  setWindowTitle("FastML-Visualizer");
}

VisualizerWidget::~VisualizerWidget() {}
