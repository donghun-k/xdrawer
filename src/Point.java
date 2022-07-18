import java.awt.Color;
import java.awt.Graphics;
import java.io.Serial;

public class Point extends OnePointFigure {

  @Serial
  private static final long serialVersionUID = -4403256306936776557L;

  Point(Color color) {
    super(color);
  }

  Point(Color color, int x, int y) {
    super(color, x, y);
  }

  void draw(Graphics g) {
    g.setColor(color);
    g.drawOval(x1 - GAP, y1 - GAP, GAP * 2, GAP * 2);
    g.fillOval(x1 - GAP, y1 - GAP, GAP * 2, GAP * 2);
  }

  Figure copy() {
    Point newPoint = new Point(color, x1, y1);
    newPoint.popup = popup;
    newPoint.move(MOVE_DX, MOVE_DY);
    return newPoint;
  }
}
