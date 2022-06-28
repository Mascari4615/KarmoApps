import java.util.Scanner;
public class ProgramEx 
{

	public static void main(String[] args) 
	{
		// �� ��ü�� �����ڸ� ���� �ʱ�ȭ�ϰ� Describe �Լ� ȣ��
		
		Student student = new Student(2, 4);
		student.describe();
		
		StudentWorker studentWorker = new StudentWorker(2, 4, 100, "Programmer");
		studentWorker.describe();
		
		Researcher researcher = new Researcher("ABC Lab", "Game");
		researcher.describe();
		
		Professor professor = new Professor("ABC Lab", "Game", "GWNU", 5);
		professor.describe();
	}

}

abstract class Person
{
	// ���� �⺻�� �Ǵ� Ŭ����
	// ���ϱ�, �Ա�, �ȱ�, �ڱ� �Լ��� �����Ǿ� �ְ�
	// �߻� �޼ҵ�� Describe�� �ִ�
	
	protected void Talk()
	{
		System.out.println("I can talk.");
	}
	
	protected void Eat()
	{
		System.out.println("I can eat.");
	}
	
	protected void Walk()
	{
		System.out.println("I can walk.");
	}
	
	protected void Sleep()
	{
		System.out.println("I can sleep.");
	}
	
	abstract public void describe();
}

class Student extends Person
{
	// Person �߻� Ŭ������ �θ���ϴ� Student Ŭ����
	// ���� �޼ҵ�, Describe �޼ҵ�� ���� �г�, ���� �ʵ尡 �����Ǿ� �ִ�.
	int curGrade;
	int curScore;
	public Student(int curGrade, int curScore)
	{
		this.curGrade = curGrade;
		this.curScore = curScore;
	}
	protected void Study()
	{
		System.out.println("I can study");
	}
	
	@Override
	public void describe() {
		System.out.println("Student Describe = curGrade : " + curGrade + ", curScore : " + curScore);
	}
	
}

class StudentWorker extends Student
{
	// Student Ŭ������ �θ���ϴ� StudentWorker Ŭ����
	// �� �޼ҵ�, Describe �޼ҵ�� ��, ���� �ʵ尡 �����Ǿ� �ִ�.
	int money;
	String job;
	public StudentWorker(int curGrade, int curScore, int money, String job)
	{
		super(curGrade, curScore);
		this.money = money;
		this.job = job;
	}
	protected void Work()
	{
		System.out.println("I can Work");
	}

	@Override
	public void describe() {
		System.out.println("StudentWorker Describe = curGrade : " + curGrade + ", curScore : " + curScore+ ", money : " + money+ ", job : " + job);
	}
	
}

class Researcher extends Person
{
	// Person Ŭ������ �θ���ϴ� Researcher Ŭ����
	// ���� �޼ҵ�, Describe �޼ҵ�� ������, �о� �ʵ尡 �����Ǿ� �ִ�.
	String laboratory;
	String department;
	public Researcher(String laboratory, String department)
	{
		this.laboratory = laboratory;
		this.department = department;
	}
	protected void Research()
	{
		System.out.println("I can Research");
	}
	
	@Override
	public void describe() {
		System.out.println("Researcher Describe = laboratory : " + laboratory + ", department : " + department);
	}
	
}

class Professor extends Researcher
{
	// Researcher Ŭ������ �θ���ϴ� Professor Ŭ����
	// ����ġ�� �޼ҵ�, Describe �޼ҵ�� ����, �� �� �ʵ尡 �����Ǿ� �ִ�.
	
	String university;
	int thesisCount;
	public Professor(String laboratory, String department, String university, int thesisCount)
	{
		super(laboratory, department);
		this.university = university;
		this.thesisCount = thesisCount;
	}
	protected void Teach()
	{
		System.out.println("I can Teach");
	}
	
	@Override
	public void describe() {
		System.out.println("Professor Describe = laboratory : " + laboratory + ", department : " + department + ",university : " + university + ", thesisCount : " + thesisCount);
	}
	
}