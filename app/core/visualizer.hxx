#ifndef FASTML_APP_CORE_VISUALIZER
#define FASTML_APP_CORE_VISUALIZER

#include <QProcess>
#include <QSlider>
#include <QWidget>

class QPushButton;
class QTextBrowser;

class VisualizerWidget : public QWidget {
  Q_OBJECT

public:
  explicit VisualizerWidget(QWidget *parent = nullptr);
  ~VisualizerWidget();

private slots:

private:
  QSlider *trainPercentageSlider;
};

#endif
