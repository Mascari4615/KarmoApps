
struct Address
{
	char name[10];
	char phoneNumber[13];
	char address[10];
	char birthDay[10];
	//��� �߰� Ž�� ����
};

void PrintAddresses()


void Program2_24()
{
	struct Address addresses[4] =
	{
		{"������", "010-0000-0000", "����", "1�� 1��"},
		{"�󸶹�", "010-1111-1111", "��õ", "2�� 1��"},
		{"�����", "010-2222-2222", "�۵�", "3�� 1��"},
		{"��īŸ", "010-3333-3333", "�λ�", "4�� 1��"},
	};

	while (1)
	{
		int command = 4;

		printf("����� �Է��ϼ��� : ");
		scanf("%d", &command);

		switch (command)
		{
			case 0: // ���
				printf("�̸�\t\t��ȣ\t\t�ּ�\t\t����\n");
				for (int i = 0; i < sizeof(addresses) / sizeof(struct Address); i++)
				{
					printf("%s\t\t%s\t\t%s\t\t%s\n", addresses[i].name, addresses[i].phoneNumber, addresses[i].address, addresses[i].birthDay);
				}
				break;
			case 1: // �߰�
				exit(0);
				break;
			case 2: // Ž��
				exit(0);
				break;
			case 3: // ����
				printf("������ �Է��ϼ��� : ");
				scanf("%d", &command);
				break;
			case 4: // ����
				exit(0);
				break;
			default:
				break;
		}
	}

}

void main()
{
	return 0;
}