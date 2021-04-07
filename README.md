# Trabalho Prático de Computação Gráfica 2020.2
## Campus da UFC em Russas

### Integrantes
- Alan Sousa da Silva (400261)
- Cícero Romão Ribeiro Pereira Filho (411674)

### Descrição do Projeto
- Projeto que visa execução de conteúdos mostrados em aula, como: Iluminação, câmera, movimentação, colisão, leitura de arquivos entre outros.
- A ideia implementada foi mostrar a mudança um personagem de acordo com suas versões. No caso o personagem escolhido foi o [Hulk](https://www.google.com/search?q=hulk).
- Na prática o usuário tem um câmera que visualiza o personagem e o mesmo pode selecionar entre suas versões.

### Dados de Implementação
- Projeto implementado em C++(com OO).
- Classes Implementadas: main, Câmera, ObjLoader, Ponto.
- Foram utilizadas Glut e OpenGL como APIs de computação gráfica.

### Dependências e Execução
- Windows
[Instalação das APIs.](https://w3.cs.jmu.edu/bernstdh/web/common/help/cpp_mingw-glut-setup.php){:target="_blank"}  
Comando para compilar o projeto: g++ *.cpp -mwindows glut32.lib -lopengl32 -lglu32  
Execução: a.exe
- Linux
[Instalação das APIs.](https://gist.github.com/AbdullahKady/f2782157991df652c2baee0bba05b788){:target="_blank"}  
Comando para compilar o projeto: g++ *.cpp -lglut -lGLU -lGL -lm  
Execução: ./a

### Modelos
[Rip Van Winkle in RenderHub](https://www.renderhub.com/rip-van-winkle)