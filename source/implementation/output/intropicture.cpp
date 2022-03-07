#include "intropicture.h"
#include <QDebug>


namespace Night
{
    IntroPicture::IntroPicture(QWidget *parent)
        : QGraphicsView(parent)
    {
        QImage image;

        m_Gfx = new QGraphicsScene(this);

        image.load("/mnt/Projects/Projects/Rhana/sandbox/source/assets/pictures/midnight.jpg");
        if (image.isNull())
        {
            qDebug() << "Error: Unable to find file";
        }
        m_Gfx->addPixmap(QPixmap::fromImage(image));

        this->setScene(m_Gfx);

    }

    IntroPicture::~IntroPicture()
    {
        delete m_Gfx;
    }
}
