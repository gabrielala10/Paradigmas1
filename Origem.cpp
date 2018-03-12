#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <locale.h>
#include <math.h>

struct alunos {
	char nome[20];
	int ra;
	int yes = 0;
	int numero = 0;
	int nmaterias = 0;
	int materias[20];
};
struct professores {
	char nome[20];
	int id;
	int yes = 0;
	int numero;
	int nmaterias = 0;
	int materias[20];
};
struct materias {
	char nome[20];
	int id;
	int numero;
	int nprofessores = 0;
	int professores[20];
	int nalunos = 0;
	int alunos[20];
};
void printprof( professores cad[20], int numero);
void printal(alunos cad[20], int numero);
void printdisc(materias cad[20], int numero);
void printvinculo(materias mat[20], int vet[20], int op);
void printmenu();

enum menu { aluno = 1, professor, disciplina, matricula, desmatricula, vincular, desvincular, dados, sair };
void main()
{
	setlocale(LC_ALL, "Portuguese");

	int i, j, u, f, temp, tempp, ver;
	int op;
	char al[2];

	alunos estudantes[20];
	professores profs[20];
	materias mats[20];

	int ncad, ncadd;
	int apaga;
	int nop;
	int vet[20];
	int vet2[20];
	int mat[20][20] = { 0 };
	int nalunos = 0;
	int ndisciplinas = 0;
	int nprofessores = 0;

	do {
		printmenu();
		scanf("%i", &op);

		switch (op)
		{
		case aluno:
			printf("\t\t\t\tDigite o número de alunos que deseja cadastrar: ");
			scanf("%i", &ncad);
			for (i = 0; i < ncad; i++)
			{
				printf("\n\t\t\t\t%i aluno(s) cadastrado(s)\n\n", nalunos);
				printf("\t\t\t\tCadastrando aluno %i de %i:\n", i + 1, ncad);
				printf("\t\t\t\tDigite o nome do %i%c aluno(a): ", i + 1, 186);
				gets_s(al);
				gets_s(estudantes[nalunos].nome);
				printf("\t\t\t\tDigite o RA do aluno(a): ");
				scanf("%d", &estudantes[nalunos].ra);
				printf("\t\t\t\tAluno(a) %s cadastrado com sucesso!\n", estudantes[nalunos].nome);
				nalunos++;
			}
			printf("\n\t\t\t\t%i aluno(s) cadastrado(s)\n\n", nalunos);
			break;
		case professor:
			printf("\t\t\t\tDigite o número de professores que deseja cadastrar: ");
			scanf("%i", &ncad);
			for (i = 0; i < ncad; i++)
			{
				printf("\n\t\t\t\t%i professor(es) cadastrado(s)\n\n", nprofessores);
				printf("\t\t\t\tCadastrando professor %i de %i:\n", i + 1, ncad);
				printf("\t\t\t\tDigite o nome do %i%c professor(a): ", i + 1, 186);
				gets_s(al);
				gets_s(profs[nprofessores].nome);
				printf("\t\t\t\tDigite o código do professor(a): ");
				scanf("%i", &profs[nprofessores].id);
				printf("\t\t\t\tProfessor(a) %s cadastrado com sucesso!\n", profs[nprofessores].nome);
				nprofessores++;
			}
			printf("\n\t\t\t\t%i professor(es) cadastrado(s)\n\n", nprofessores);
			break;
		case disciplina:
			printf("\t\t\t\tDigite o número de disciplinas que deseja cadastrar: ");
			scanf("%i", &ncad);
			for (i = 0; i < ncad; i++)
			{
				printf("\n\t\t\t\t%i disciplina(s) cadastrada(s)\n\n", ndisciplinas);
				printf("\t\t\t\tCadastrando disciplina %i de %i:\n", i + 1, ncad);
				printf("\t\t\t\tDigite o nome da %i%c disciplina: ", i + 1, 186);
				gets_s(al);
				gets_s(mats[ndisciplinas].nome);
				printf("\t\t\t\tDigite o código do disciplina: ");
				scanf("%i", &mats[ndisciplinas].id);
				printf("\t\t\t\tDisciplina de %s cadastrado com sucesso!\n", mats[ndisciplinas].nome);
				ndisciplinas++;
			}
			printf("\n\t\t\t\t%i disciplina(s) cadastrada(s)\n\n", ndisciplinas);
			break;
		case matricula:
			mat[20][20] = { 0 };
			if (nalunos == 0 || ndisciplinas == 0)
			{
				printf("\n\t\t\t\tAlunos ou disciplinas insuficientes para matrícula!");
				break;
			}
			do
			{
				printf("\t\t\t\tA faculdade tem %i alunos cadastrados\n", nalunos);
				printf("\t\t\t\tDigite quantos alunos deseja matricular: ");
				scanf("%i", &ncad);
				if (ncad > nalunos)
					printf("\t\t\t\tAlunos insuficientes para matrícula\n");
			} while (ncad > nalunos);
			if (ncad <= 0)
				break;

			printal(estudantes, nalunos);

			for (i = 0; i < ncad; i++)
			{
				printf("\t\t\t\tDigite o código do %i%c aluno(a) para matrícula: ", i + 1, 186);
				scanf("%i", &nop);
				if (nop > 0 && nop <= nalunos)
				{
					vet[i] = nop - 1;
				}
				else
				{
					printf("\t\t\t\tAluno não cadastrado, digite um número válido.\n");
					i--;
				}
				printf("\t\t\t\tAluno(a) %s armazenado com sucesso!\n", estudantes[vet[i]].nome);
			}
			do
			{
				printf("\t\t\t\tA faculdade tem %i disciplina(s) cadastrada(s)\n", ndisciplinas);
				printf("\t\t\t\tDigite o número de disciplinas para matrícula: ");
				scanf("%i", &ncadd);
				if (ncadd > ndisciplinas)
					printf("\t\t\t\tDisciplinas insuficientes para matrícula\n");
			} while (ncadd > ndisciplinas);
			if (ncadd <= 0)
				break;

			printdisc(mats, ndisciplinas);
			
			for (i = 0; i < ncadd; i++)
			{
				printf("\t\t\t\tDigite o código da %i%c disciplina para matrícula: ", i + 1, 186);
				scanf("%i", &nop);
				nop--;
				vet2[i] = nop;
				if (nop >= 0 && nop < ndisciplinas)
				{
					u = 0;
					tempp = mats[nop].nalunos;
					f = 0;
					for (j = mats[nop].nalunos; j < ncad + tempp - f; j++)
					{
						temp = estudantes[vet[u]].nmaterias;
						for (ver = 0; ver < temp; ver++)
						{
							if (nop == estudantes[vet[u]].materias[ver])
							{
								estudantes[vet[u]].numero = 1;
								mat[vet[u]][nop] = 1;
								ver = temp;
								f++;
								j--;
							}
						}
						if (estudantes[vet[u]].numero != 1)
						{
							estudantes[vet[u]].yes = 1;
							mats[nop].nalunos++;
							mats[nop].alunos[j] = vet[u];
							estudantes[vet[u]].materias[temp] = nop;
							estudantes[vet[u]].nmaterias++;
						}
						estudantes[vet[u]].numero = 0;
						u++;
					}
					
				}
				else
				{
					printf("\t\t\t\tDisciplina não cadastrada, digite um número válido.\n");
					i--;
				}
				//printf("\t\t\t\tAlunos cadastrados com sucesso.\n");
			}
			for (i = 0; i < ncadd; i++)
				for (j = 0; j < ncad; j++)
				{
					if (mat[j][i] != 1)
						printf("\t\t\t\tO(A) aluno(a) %s foi matriculado(a) em %s\n", estudantes[vet[j]].nome, mats[vet2[i]].nome);
					else
						printf("\t\t\t\tO(A) aluno(a) %s  já estava matriculado(a) em %s\n", estudantes[vet[j]].nome, mats[vet2[i]].nome);
				}

			break;
		case desmatricula:
			mat[20][20] = { 0 };
			temp = 0;
			for (i = 0; i < nalunos; i++)
				if (estudantes[i].yes == 1)
					temp++;
			
			do
			{
				printf("\n\t\t\t\tA faculdade tem %i alunos matriculados\n", temp);
				printf("\t\t\t\tDigite quantos alunos deseja desmatricular: ");
				scanf("%i", &ncad);
				if (ncad > temp)
					printf("\t\t\t\tAlunos insuficientes para desmatrícula\n");
			} while (ncad > nalunos);

			printal(estudantes, nalunos);

			printf("\t\t\t\t________________________________________________________\n");
			if (ncad >= 0)
				for (i = 0; i < ncad; i++)
				{
					printf("\t\t\t\tDigite o código do %i%c aluno(a) para a desmatrícula: ", i + 1, 186);
					scanf("%i", &nop);
					if (nop > 0 && nop <= nalunos)
					{
						vet[i] = nop - 1;
					}
					else
					{
						printf("\t\t\t\tAluno não cadastrado, digite um número válido.\n");
						i--;
					}
					printf("\t\t\t\t=====================================================\n", estudantes[vet[i]].nome);
				}
			do
			{
				printf("\t\t\t\tA faculdade tem %i disciplina(s) cadastrada(s)\n", ndisciplinas);
				printf("\t\t\t\tDigite o número de disciplinas para desmatrícula: ");
				scanf("%i", &ncadd);
				if (ncadd > ndisciplinas)
					printf("\t\t\t\tDisciplinas insuficientes para desmatrícula\n");
			} while (ncadd > ndisciplinas);
			if (ncadd <= 0)
				break;

			printdisc(mats, ndisciplinas);

			for (i = 0; i < ncadd; i++)
			{
				printf("\t\t\t\tDigite o código da %i%c disciplina para desmatrícula: ", i + 1, 186);
				scanf("%i", &nop);
				nop--;
				vet2[i] = nop;
				if (nop >= 0 && nop < ndisciplinas)
				{
					u = 0;
					tempp = mats[nop].nalunos;
					temp = i;
					f = 0;
					for (i = 0; i < ncad; i++)
					{
						apaga = 0;
						for (j = 0; j < mats[nop].nalunos; j++)
						{
							if (vet[i] == mats[nop].alunos[j] || apaga == 1)
							{
								apaga = 1;
								mats[nop].alunos[j] = mats[nop].alunos[j + 1];
								
								
							}
						}

						if (apaga == 1)
						{
							for (j = 0; j < estudantes[i].nmaterias; j++)
							{
								if (nop == estudantes[i].materias[j] || apaga == 0)
								{
									apaga = 0;
									estudantes[i].materias[j] = estudantes[i].materias[j + 1];
									mat[i][temp] = 1;
								}
							}
							mats[nop].nalunos--;
							estudantes[i].nmaterias--;
							apaga = 0;
							if (estudantes[i].nmaterias == 0)
								estudantes[i].yes = 0;
						}
						else
							mat[i][nop] = 1;
					}

					i = temp;
				}
				else
				{
					printf("\t\t\t\tDisciplina não cadastrada, digite um número válido.\n");
					i--;
				}
				//printf("\t\t\t\tAlunos cadastrados com sucesso.\n");
			}
			for (i = 0; i < ncadd; i++)
				for (j = 0; j < ncad; j++)
				{
					if (mat[j][i] == 1)
						printf("\t\t\t\tO(A) aluno(a) %s foi desmatriculado(a) de %s\n", estudantes[vet[j]].nome, mats[vet2[i]].nome);
					else
						printf("\t\t\t\tO(A) aluno(a) %s não estava matriculado(a) em %s\n", estudantes[vet[j]].nome, mats[vet2[i]].nome);
				}

				break;
				printal(estudantes, nalunos);

			break;
		case vincular:
			if (nprofessores == 0 || ndisciplinas == 0)
			{
				printf("\n\t\t\t\tProfessores ou disciplinas insuficientes para matrícula!");
				break;
			}
			do
			{
				printf("\t\t\t\tA faculdade tem %i professores cadastrados\n", nprofessores);
				printf("\t\t\t\tDigite quantos professores deseja vincular: ");
				scanf("%i", &ncad);
				if (ncad > nprofessores)
					printf("\t\t\t\tProfessores insuficientes para matrícula\n");
			} while (ncad > nprofessores);
			if (ncad <= 0)
				break;

			printprof(profs, nprofessores);

			for (i = 0; i < ncad; i++)
			{
				printf("\t\t\t\tDigite o código do %i%c professor(a) para matrícula: ", i + 1, 186);
				scanf("%i", &nop);
				if (nop > 0 && nop <= nalunos)
				{
					vet[i] = nop - 1;
				}
				else
				{
					printf("\t\t\t\tProfessor(a) não cadastrado(a), digite um número válido.\n");
					i--;
				}
				printf("\t\t\t\tProfessor(a) %s armazenado com sucesso!\n", profs[vet[i]].nome);
			}
			do
			{
				printf("\t\t\t\tA faculdade tem %i disciplina(s) cadastrada(s)\n", ndisciplinas);
				printf("\t\t\t\tDigite o número de disciplinas para vincular: ");
				scanf("%i", &ncadd);
				if (ncadd > ndisciplinas)
					printf("\t\t\t\tDisciplinas insuficientes para vincular\n");
			} while (ncadd > ndisciplinas);
			if (ncadd <= 0)
				break;

			printdisc(mats, ndisciplinas);

			for (i = 0; i < ncadd; i++)
			{
				printf("\t\t\t\tDigite o código da %i%c disciplina: ", i + 1, 186);
				scanf("%i", &nop);
				nop--;
				vet2[i] = nop;
				if (nop >= 0 && nop < ndisciplinas)
				{
					u = 0;
					tempp = mats[nop].nprofessores;
					f = 0;
					for (j = mats[nop].nprofessores; j < ncad + tempp - f; j++)
					{
						temp = profs[vet[u]].nmaterias;
						for (ver = 0; ver < temp; ver++)
						{
							if (nop == profs[vet[u]].materias[ver])
							{
								profs[vet[u]].numero = 1;
								mat[u][nop] = 1;
								ver = temp;
								f++;
								j--;
							}
						}
						if (profs[vet[u]].numero != 1)
						{
							mats[nop].nprofessores++;
							mats[nop].professores[j] = vet[u];
							profs[vet[u]].materias[temp] = nop;
							profs[vet[u]].nmaterias++;
							profs[vet[u]].yes = 1;
						}
						profs[vet[u]].numero = 0;
						u++;
					}

				}
				else
				{
					printf("\t\t\t\tDisciplina não cadastrada, digite um número válido.\n");
					i--;
				}
				//printf("\t\t\t\tAlunos cadastrados com sucesso.\n");
			}
			for (i = 0; i < ncadd; i++)
				for (j = 0; j < ncad; j++)
				{
					if (mat[j][i] != 1)
						printf("\t\t\t\tO(A) professos(a) %s foi vinculado(a) a %s\n", profs[vet[j]].nome, mats[vet2[i]].nome);
					else
						printf("\t\t\t\tO(A) professor(a) %s  já estava vinculado(a) a %s\n", profs[vet[j]].nome, mats[vet2[i]].nome);
				}

			break;
		case desvincular:
			mat[20][20] = { 1 };
			temp = 0;
			for (i = 0; i < nprofessores; i++)
				if (profs[i].yes == 1)
					temp++;

			do
			{
				printf("\n\t\t\t\tA faculdade tem %i professores lecionando\n", temp);
				if (nprofessores > 0)
				{
					printprof(profs, nprofessores);
				}
				else
				{
					printf("\t\t\t\tNão há nenhum professor cadastrado no sistema\n");
					break;
				}
				printf("\t\t\t\t____________________________________________________\n");
				printf("\t\t\t\tDigite quantos professores deseja desvincular: ");
				scanf("%i", &ncad);
				if (ncad > temp)
					printf("\t\t\t\tProfessores insuficientes insuficientes\n");
			} while (ncad > nprofessores);
			if (ncad >= 0)
				for (i = 0; i < ncad; i++)
				{
					printf("\t\t\t\tDigite o código do %i%c professor(a): ", i + 1, 186);
					scanf("%i", &nop);
					if (nop > 0 && nop <= nprofessores)
					{
						vet[i] = nop - 1;
					}
					else
					{
						printf("\t\t\t\tProfessor não cadastrado, digite um número válido.\n");
						i--;
					}
					printf("\t\t\t\t=================================================\n");
				}
			do
			{
				printf("\t\t\t\tA faculdade tem %i disciplina(s) cadastrada(s)\n", ndisciplinas);
				printf("\t\t\t\tDigite o número de disciplinas: ");
				scanf("%i", &ncadd);
				if (ncadd > ndisciplinas)
					printf("\t\t\t\tDisciplinas insuficientes\n");
			} while (ncadd > ndisciplinas);
			if (ncadd <= 0)
				break;

			printdisc(mats, ndisciplinas);

			for (i = 0; i < ncadd; i++)
			{
				printf("\t\t\t\tDigite o código da %i%c disciplina: ", i + 1, 186);
				scanf("%i", &nop);
				nop--;
				vet2[i] = nop;
				if (nop >= 0 && nop < ndisciplinas)
				{
					u = 0;
					tempp = mats[nop].nprofessores;
					temp = i;
					f = 0;
					for (i = 0; i < ncad; i++)
					{
						apaga = 0;
						for (j = 0; j < mats[nop].nprofessores; j++)
						{
							if (vet[i] == mats[nop].professores[j] || apaga == 1)
							{
								apaga = 1;
								mats[nop].professores[j] = mats[nop].professores[j + 1];

							}
						}
						if (apaga == 1)
						{
							mat[i][nop] = 0;
							for (j = 0; j < profs[i].nmaterias; j++)
							{
								if (nop == profs[i].materias[j] || apaga == 0)
								{
									apaga = 0;
									profs[i].materias[j] = profs[i].materias[j + 1];
								}
							}
							mats[nop].nprofessores--;
							profs[i].nmaterias--;
							apaga = 0;
							if (profs[i].nmaterias == 0)
								profs[i].yes = 0;
						}
						else
							mat[i][nop] = 1;
					}

					i = temp;
				}
				else
				{
					printf("\t\t\t\tDisciplina não cadastrada, digite um número válido.\n");
					i--;
				}
				//printf("\t\t\t\tAlunos cadastrados com sucesso.\n");
			}
			for (i = 0; i < ncadd; i++)
				for (j = 0; j < ncad; j++)
				{
					if (mat[j][i] != 1)
						printf("\t\t\t\tO(A) aluno(a) %s foi desmatriculado(a) de %s\n", profs[vet[j]].nome, mats[vet2[i]].nome);
					else
						printf("\t\t\t\tO(A) aluno(a) %s não estava matriculado(a) em %s\n", profs[vet[j]].nome, mats[vet2[i]].nome);
				}

			break;

			printf("\t\t\t\tAluno(s) cadastrado(s) no sistema:\n");
			for (i = 0; i < nprofessores; i++)
			{
				printf("\t\t\t\t________________________________________________________\n\n");
				printf("\t\t\t\t%i%c %s\n", i + 1, 186, profs[i].nome);
			}
			printf("\t\t\t\t________________________________________________________\n");

			break;

		case dados:
			printf("\t\t\t\t............... Selecione a opção desejada .............\n");
			printf("\t\t\t\t________________________________________________________\n\n");
			printf("\t\t\t\t1 ...................Lista de alunos....................\n");
			printf("\t\t\t\t2 .................Lista de professores.................\n");
			printf("\t\t\t\t3 .................Lista de disciplinas.................\n");
			printf("\t\t\t\t4 .................Disciplinas de aluno.................\n");
			printf("\t\t\t\t5 .................Alunos de disciplina.................\n");
			printf("\t\t\t\t6 ...............Disciplinas de professor...............\n");
			printf("\t\t\t\t7 ...............Professores de disciplina..............\n");
			printf("\t\t\t\t________________________________________________________\n\t\t\t\tOpção: ");
			scanf("%i", &op);
			switch (op)
			{
			case 1:
				printal(estudantes, nalunos);

				break;
			case 2:
				printprof(profs, nprofessores);
				break;
			case 3:
				printdisc(mats, ndisciplinas);
				break;
			case 4:
				if (nalunos > 0)
				{
					printal(estudantes, nalunos);
				}
				else
				{
					printf("\t\t\t\tNão há nenhum aluno cadastrado no sistema\n");
					break;
				}
				printf("\t\t\t\t________________________________________________________\n");
				printf("\t\t\t\tDigite o número do aluno a ser verificado: ");
				scanf("%i", &op);
				printf("\t\t\t\tDisciplina(s) cadastrada(s) do(a) aluno(a) %s:\n", estudantes[op - 1].nome);
				printvinculo(mats, estudantes[op - 1].materias, estudantes[op - 1].nmaterias);
				break;
			case 5:
				if (ndisciplinas > 0)
				{
					printdisc(mats, ndisciplinas);
				}
				else
				{
					printf("\t\t\t\tNão há nenhumuma disciplina cadastrada no sistema\n");
					break;
				}
				printf("\t\t\t\t____________________________________________________________\n");
				printf("\t\t\t\tDigite o número da disciplina a ser verificada: ");
				scanf("%i", &op);
				printf("\t\t\t\tAluno(s) matriculado(s) na disciplina de %s:\n", mats[op - 1].nome);


				for (i = 0; i < mats[op - 1].nalunos; i++)
				{
					printf("\t\t\t\t____________________________________________________________\n\n");
					temp = mats[op - 1].alunos[i];
					printf("\t\t\t\t%i%c %s\n", i + 1, 186, estudantes[temp].nome);
				}
				break;
			case 6:
				if (nprofessores > 0)
				{
					printprof(profs, nprofessores);
				}
				else
				{
					printf("\t\t\t\tNão há nenhum professor(a) cadastrado(a) no sistema\n");
					break;
				}
				printf("\t\t\t\t________________________________________________________\n");
				printf("\t\t\t\tDigite o número do professor a ser verificado: ");
				scanf("%i", &op);
				printf("\t\t\t\tDisciplina(s) vinculada(s) ao professor(a) %s:\n", profs[op - 1].nome);
				for (i = 0; i < profs[op - 1].nmaterias; i++)
				{
					printf("\t\t\t\t________________________________________________________\n\n");
					temp = profs[op - 1].materias[i];
					printf("\t\t\t\t%i%c %s\n", i + 1, 186, mats[temp].nome);
				}
				break;
			case 7:
				if (ndisciplinas > 0)
				{
					printdisc(mats, ndisciplinas);
				}
				else
				{
					printf("\t\t\t\tNão há nenhumuma disciplina cadastrada no sistema\n");
					break;
				}
				printf("\t\t\t\t________________________________________________________\n");
				printf("\t\t\t\tDigite o número da disciplina a ser verificada: ");
				scanf("%i", &op);
				printf("\t\t\t\tProfessor(es) matriculado(s) na disciplina de %s:\n", mats[op - 1].nome);
				for (i = 0; i < mats[op - 1].nprofessores; i++)
				{
					printf("\t\t\t\t________________________________________________________\n\n");
					temp = mats[op - 1].professores[i];
					printf("\t\t\t\t%i%c %s\n", i + 1, 186, profs[temp].nome);
				}
				break;
			}
			break;
		case sair:
			break;
		}
	} while (op != 9);

}

void printvinculo(materias mat[20], int vet[20], int op)
{
	int i, temp;
	for (i = 0; i < op; i++)
	{
		printf("\t\t\t\t________________________________________________________\n\n");
		temp = vet[i];
		printf("\t\t\t\t%i%c %s\n", i + 1, 186, mat[temp].nome);
	}
}
void printdisc(materias cad[20], int numero)
{
	int i;
	if (numero > 0)
	{
		printf("\t\t\t\tDisciplina(s) cadastrada(s) no sistema:\n");
		for (i = 0; i < numero; i++)
		{
			printf("\t\t\t\t________________________________________________________\n\n");
			printf("\t\t\t\t%i%c %s ID.: %i\n", i + 1, 186, cad[i].nome, cad[i].id);
		}
	}
	else
		printf("\t\t\t\tNão há nenhuma disciplina cadastrada no sistema\n");
	printf("\t\t\t\t________________________________________________________\n");
}

void printal(alunos cad[20], int numero)
{
	int i;
	if (numero > 0)
	{
		printf("\t\t\t\tAluno(s) cadastrado(s) no sistema:\n");
		for (i = 0; i < numero; i++)
		{
			printf("\t\t\t\t____________________________________________________________\n\n");
			printf("\t\t\t\t%i%c %s RA.: %i\n", i + 1, 186, cad[i].nome, cad[i].ra);
		}
	}
	else
		printf("\t\t\t\tNão há nenhum aluno cadastrado no sistema\n");
	printf("\t\t\t\t____________________________________________________________\n");
}

void printprof(professores cad[20], int numero)
{
	int i;
	if (numero > 0)
	{
		printf("\t\t\t\tProfessor(es) cadastrado(s) no sistema:\n");
		for (i = 0; i < numero; i++)
		{
			printf("\t\t\t\t________________________________________________________\n\n");
			printf("\t\t\t\t%i%c %s ID.: %i\n", i + 1, 186, cad[i].nome, cad[i].id);
		}
	}
	else
		printf("\t\t\t\tNão há nenhum professor cadastrado no sistema\n");
	printf("\t\t\t\t________________________________________________________\n");
}


void printmenu()
{
	printf("\n");
	printf("\t\t\t\t......................... Menu .........................\n");
	printf("\t\t\t\t________________________________________________________\n\n");
	printf("\t\t\t\t1 .................. Cadastrar alunos ..................\n");
	printf("\t\t\t\t2 ................ Cadastrar professores ...............\n");
	printf("\t\t\t\t3 ................ Cadastrar disciplinas ...............\n");
	printf("\t\t\t\t4 .......... Matricular alunos nas disciplinas .........\n");
	printf("\t\t\t\t5 ............ Cancelar matrícula de alunos ............\n");
	printf("\t\t\t\t6 ......... Vincular professores a disciplinas .........\n");
	printf("\t\t\t\t7 ....... Desvincular professores de disciplinas .......\n");
	printf("\t\t\t\t8 ................... Analizar dados ...................\n");
	printf("\t\t\t\t9 ........................ Sair ........................\n");
	printf("\t\t\t\t________________________________________________________\n");
	printf("\t\t\t\tDigite o número da opção desejada:  ");
}