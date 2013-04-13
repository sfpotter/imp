// lineBrush.cpp

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "lineBrush.h"

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name)
  : ImpBrush(pDoc, name)
{
}

void
LineBrush::BrushBegin(const ImpBrush::Point source, const ImpBrush::Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  glLineWidth(pDoc->getLineWidth());
  BrushMove(source, target);
}

void
LineBrush::BrushMove(const ImpBrush::Point source, const ImpBrush::Point target)
{
  ImpressionistDoc* pDoc = GetDocument();
  ImpressionistUI* dlg = pDoc->m_pUI;

  if (pDoc == NULL)
  {
    printf("LineBrush::BrushMove document is NULL\n");
    return;
  }

  glBegin(GL_LINES);
  {
    float size = (float)pDoc->getSize();
    SetColor(source);
    glVertex2d((float)target.x - size / 2.0f, target.y);
    glVertex2d((float)target.x + size / 2.0f, target.y);
  }
  glEnd();
}

void
LineBrush::BrushEnd(const ImpBrush::Point source, const ImpBrush::Point target)
{
  glLineWidth(1);
}
