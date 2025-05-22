#include "struct_string.h"
#include <stdlib.h>  // abs(x)
#include <stdio.h>   // printf
#include <string.h> 
// Exercise 1
/* Print fraction pointed to by pf in the form a/b. */
void print_fraction(const fraction_t* pf)
{
   printf("%d/%d\n", pf->num, pf->den);
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.  Copy this function from Lab 6.  No changes are needed.
*/
int gcd(int a, int b)
{
   int p, q;
   p = abs(a);
   q = abs(b);
   int r = p % q;
   while (r != 0) {
      r = q % p;
      q = p;
      p = r;
      
   }
	return q;
}

/* Updates the fraction pointed to by pf to its reduced form.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
	   positive, and the numerator and denominator have no common
	   divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
	   are made positive, or if the numerator is positive and the 
	   denominator is negative, the numerator is made negative and the 
	   denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
	   common divisor. 
*/
void reduce(fraction_t* pf)
{
   if (pf->num == 0) {
      pf->den = 1;
   }
   if (pf->den < 0) {
      pf->num = pf->num * -1;
      pf->den = pf->den * -1;
   }
   int q = gcd(pf->num, pf->den);
   pf->num = pf->num / q;
   pf->den = pf->den / q;
}

/* Returns a pointer to a fraction (by reference) with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form.
*/
void make_fraction(int a, int b, fraction_t* pf)
{
   pf -> num = a;
   pf -> den = b;
   reduce(pf);
    
}

/* Returns by reference a pointer to the sum of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void add_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* psum)
{
   int numerator = pf1 -> num * pf2 -> den + pf1 -> den * pf2 -> num;
   int denominator = pf1 -> den * pf2 -> den;
   return make_fraction(numerator, denominator, psum); 
}

/* Returns by reference a pointer to the product of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void multiply_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* pprod)
{
   int new_num = pf1 -> num * pf2 -> num; 
   int new_den = pf1 -> den * pf2 -> den;
   make_fraction(new_num, new_den, pprod);
}

// Exercise 2

/* Update the GPA of the student pointed to by studentp, assuming the student has numGrades.	Note that update_gpa must call calc_gpa for each student. */
void update_gpa(student_t *studentp, int numGrades) {
   studentp -> gpa = calc_gpa(studentp->grades, numGrades);
}

/* Calculate the GPA associated with the numGrades pointed to by gradesp.
   The implementation must use a walking pointer. 
   If the total weight of all courses is 0, a GPA of 0 is returned. */
float calc_gpa(const grade_t *gradesp, int numGrades) {
   float gpa = 0.0; 
   float weight = 0.0; 
   for(int i = 0; i < numGrades; i++, gradesp++){
      gpa += gradesp -> gp * gradesp -> weight; 
      weight += gradesp -> weight;
   }
   return gpa/weight; 
}

// Exercise 3

/* Calculate how many time the target character appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use array-indexing. 
*/

int count_char(const char * my_str, char target){
   int found_let = 0;
   for(int i = 0; i < strlen(my_str); i++){
      if(my_str[i] == target){
         found_let++;
      }
   }
   return found_let;
}

// Exercise 4

/* Calculate how many time the target character appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use walking pointer.
*/

int count_char_wp(const char * my_str, char target){
   int found = 0;
   while(*my_str != '\0'){
      if(*my_str == target){
         found++;
      }
      my_str++;
   }
   return found; 
}