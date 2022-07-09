import java.awt.Graphics;
import java.awt.Polygon;

public abstract class Figure {

  protected Polygon region;

  Figure() {

  }

  abstract void draw(Graphics g);

  abstract void setXY2(int newX, int newY);

  abstract void makeRegion();

  boolean contains(int x, int y) {
    if (region == null) {
      return false;
    }
    return region.contains(x, y);
  }

  void drawing(Graphics g, int newX, int newY) {
//    이전 그림 지우기
    draw(g);
//    새 그림 그리기
    setXY2(newX, newY);
    draw(g);
  }
}
