import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;
import java.io.Serial;

public abstract class OnePointFigure extends Figure {

  @Serial
  private static final long serialVersionUID = -3942213484307031325L;
  protected static int GAP = 5;
  protected int x1;
  protected int y1;

  OnePointFigure(Color color) {
    super(color);
  }

  OnePointFigure(Color color, int x, int y) {
    super(color);
    x1 = x;
    y1 = y;
  }

  int getX1() {
    return x1;
  }

  int getY1() {
    return y1;
  }

  void setX1(int x) {
    x1 = x;
  }

  void setY1(int y) {
    y1 = y;
  }

  void setXY2(int x, int y) {
    setX1(x);
    setY1(y);
  }

  void makeRegion() {
    int[] xpoints = new int[4];
    int[] ypoints = new int[4];

    xpoints[0] = x1 - GAP;
    ypoints[0] = y1 - GAP;
    xpoints[1] = x1 + GAP;
    ypoints[1] = y1 - GAP;
    xpoints[2] = x1 + GAP;
    ypoints[2] = y1 + GAP;
    xpoints[3] = x1 - GAP;
    ypoints[3] = y1 + GAP;

    region = new Polygon(xpoints, ypoints, 4);
  }

  void move(int dx, int dy) {
    x1 = x1 + dx;
    y1 = y1 + dy;
  }
}
