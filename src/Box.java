import java.awt.Color;
import java.awt.Graphics;

public class Box extends TwoPointFigure {

  protected boolean fillFlag;

  Box(Color color) {
    super(color);
    fillFlag = false;
  }

  Box(Color color, int x, int y) {
    super(color, x, y);
  }

  Box(Color color, int x1, int y1, int x2, int y2) {
    super(color, x1, y1, x2, y2);
  }

  void draw(Graphics g) {
    int minX = Math.min(x1, x2);
    int minY = Math.min(y1, y2);
    int width = Math.abs(x2 - x1);
    int height = Math.abs(y2 - y1);

    g.setColor(color);
    g.drawRect(minX, minY, width, height);

    if (fillFlag) {
      g.fillRect(minX, minY, width, height);
    }
  }

  Figure copy() {
    Box newBox = new Box(color, x1, y1, x2, y2);
    newBox.popup = popup;
    newBox.move(MOVE_DX, MOVE_DY);
    newBox.fillFlag = fillFlag;
    return newBox;
  }

  void setFill() {
    fillFlag = !fillFlag;
  }
}
