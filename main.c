#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = 100;
  c.green = 0;
  c.blue = 255;

  clear_screen(s);
  
  struct matrix *edges;
  edges = new_matrix(4, 4);
  add_point(edges, 200, 150, 0);
  add_point(edges, 200, 200, 0);
  add_edge(edges, 300, 150, 0, 300, 200, 0);
  add_edge(edges, 200, 200, 0, 200, 300, 0);
  add_edge(edges, 300, 300, 0, 200, 300, 0);
  add_edge(edges, 300, 300, 0, 300, 200, 0);
  add_edge(edges, 200, 200, 0, 300, 200, 0);
  draw_lines(edges, s, c);

  struct matrix *identity;
  identity = new_matrix(4, 4);
  printf("\nCreating identity matrix\n");
  ident(identity);
  print_matrix(identity);
  printf("\nMultiplying identity matrix by a factor of 3\n");
  scalar_mult(3, identity);
  print_matrix(identity);
  
  struct matrix *test;
  test = new_matrix(4, 4);
  printf("\nCreating testing matrix\n");
  add_point(test, 1, 2, 3);
  add_edge(test, 2, 4, 6, 3, 1, 5);
  add_point(test, 2, 4, 7);
  print_matrix(test);
  printf("\nMultiplying identity matrix by testing matrix\n");
  matrix_mult(identity, test);
  print_matrix(test);

  display(s);
  save_extension(s, "lines.png");
 
  free_matrix( edges );
  free_matrix( identity );
  free_matrix( test );
} 
