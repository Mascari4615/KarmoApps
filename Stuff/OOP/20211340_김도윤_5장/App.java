import java.util.Scanner;

abstract class Calculator
{
	// ������� �θ� Ŭ���� (�߻�)
	
	protected int a, b; // ����� ���� 2��
	abstract protected int calc(); // ��� ����� ������ �߻� �޼ҵ�
	public void SetNums(int a, int b) // ���� �ʱ�ȭ
	{
		this.a = a;
		this.b = b;
	}
	public void run() // ��� �� ��� ����
	{
		int res = calc();
		System.out.println("���� ���� " + res);
	}
}

class Adder extends Calculator
{
	// �� ����
	@Override
	protected int calc() { return a + b; }
}

class Substracter extends Calculator
{
	// �� ����
	@Override
	protected int calc() { return a - b; }	
}

class Multiplier extends Calculator
{
	// �� ����
	@Override
	protected int calc() { return a * b; }
}

class Divider extends Calculator
{
	// ������ ����
	@Override
	protected int calc() { return a / b; }
}

public class App
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		System.out.print("���� 2���� �����ڸ� �Է��ϼ���>>");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		
		// ������ �Է�
		String operator = scanner.next();
		
		// �����ڿ� ���� �Է¹��� ���ڸ� ��ü�� �ʱ�ȭ ��Ű�� ��� ����
		switch(operator)
		{
		case "+":
			Adder adder = new Adder();
			adder.SetNums(a, b);
			adder.run();
			break;
		case "-":
			Substracter substracter = new Substracter();
			substracter.SetNums(a, b);
			substracter.run();
			break;
		case "*":
			Multiplier multiplier = new Multiplier();
			multiplier.SetNums(a, b);
			multiplier.run();
			break;
		case "/":
			Divider divider = new Divider();
			divider.SetNums(a, b);
			divider.run();
			break;
		}
	}
}
