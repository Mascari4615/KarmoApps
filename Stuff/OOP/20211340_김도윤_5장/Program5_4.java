import java.util.Scanner;

public class Program5_4 
{	
	public static void main(String[] args)
	{
		// lineEx ��ü�� ����� ���ÿ� �����ڸ� ���� �ʱ�ȭ
		LineEx lineEx = new LineEx(new Point(1, 2), new Point(3, 4), "Black", 1);
		
		// Start End ���
		lineEx.DrawLine();
		// Start End 0,0 �ʱ�ȭ
		lineEx.DeleteLine();
		// Start End�� 0,0���� �ʱ�ȭ �Ǿ��� �� Ȯ��
		lineEx.DrawLine();
		// ���� �Ӽ� ���
		lineEx.ShowLine();
	}
}

// �� Ŭ����
class Point
{
	private int x, y;
	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	public int Getx()
	{
		return x;
	}
	public int Gety()
	{
		return y;
	}
	protected void move(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
}

// �� Ŭ����
class Line
{
	private Point start, end;
	public Line(Point start, Point end)
	{
		this.start = start;
		this.end = end;
	}
	public Point GetStart()
	{
		return start;
	}
	public Point GetEnd()
	{
		return end;
	}
	// Start�� End �� ����Ѵ�
	public void DrawLine()
	{
		System.out.println("Start : (" + start.Getx() + ", " + start.Gety() + "), End : (" + end.Getx() + ", " + end.Gety() + ")");
	}
	// Start�� End�� ��� 0,0 ���� �ʱ�ȭ��Ű��, �����Ǿ��ٴ� �޽����� ����Ѵ�
	public void DeleteLine()
	{
		start.move(0, 0);
		end.move(0, 0);
		System.out.println("Delete Line!");
	}
	protected void move(Point start, Point end)
	{
		this.start = start;
		this.end = end;
	}
}

// �� Ŭ������ �θ�� �ϴ� LineEx Ŭ����
class LineEx extends Line
{
	private String color;
	private int thickness;
	public LineEx(Point start, Point end, String color, int thickness) 
	{
		super(start, end);
		this.color = color;
		this.thickness = thickness;
	}
	// ��� �Ӽ��� ����Ѵ�
	public void ShowLine()
	{
		System.out.println("Color : " + color + ", Thickness : " + thickness );
	}
}