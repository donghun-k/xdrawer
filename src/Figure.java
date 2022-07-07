import java.awt.Graphics;

public abstract class Figure {

  Figure() {

  }

  abstract void draw(Graphics g);

  abstract void setXY2(int newX, int newY);

  void drawing(Graphics g, int newX, int newY) {
//    이전 그림 지우기
    draw(g);
//    새 그림 그리기
    setXY2(newX, newY);
    draw(g);
  }
}
