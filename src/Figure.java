import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;

public abstract class Figure {

  protected static int MOVE_DX = 20;
  protected static int MOVE_DY = 10;

  protected Polygon region;
  protected Popup popup;
  protected Color color;

  Figure(Color color) {
    region = null;
    popup = null;
    this.color = color;
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

  abstract void move(int dx, int dy);

  abstract Figure copy();

  void move(Graphics g, int dx, int dy) {
    draw(g);
    move(dx, dy);
    draw(g);
  }


  void drawing(Graphics g, int newX, int newY) {
//    이전 그림 지우기
    draw(g);
//    새 그림 그리기
    setXY2(newX, newY);
    draw(g);
  }

  void setPopup(Popup popup) {
    this.popup = popup;
  }

  void popup(int x, int y) {
    popup.popup(x, y);
  }

  void setColor(Color color) {
    this.color = color;
  }

  //  hook function
  void setFill() {

  }

  int getX1() {
    return -1;
  }

  int getY1() {
    return -1;
  }

  int getX2() {
    return -1;
  }

  int getY2() {
    return -1;
  }
}
