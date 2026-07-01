#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

typedef struct {
  char element[MAX][MAX];
  int idxTop;
} Stack;

void initStack(Stack *s) { s->idxTop = -1; }

int isNum(char c) { return (c >= '0' && c <= '9') || c == '.'; }

int isValidDigit(char *token) {
  for (int i = 0; token[i] != '\0'; i++) {
    if (!isNum(token[i])) {
      return 0;
    }
  }
  return 1;
}

void pushStack(Stack *s, char *str) {
  if (s->idxTop < MAX - 1) {
    strcpy(s->element[++(s->idxTop)], str);
  }
}

char *peekStack(Stack *s) {
  if (s->idxTop >= 0) {
    return s->element[s->idxTop];
  }
  return "";
}

char *popStack(Stack *s) {
  if (s->idxTop >= 0) {
    return s->element[(s->idxTop)--];
  }
  return "";
}

int isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char *str) {
  switch (str[0]) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

void shuntingYard(char expression[], char postFixResult[]) {
  Stack operatorStack;
  Stack resultStack;
  initStack(&operatorStack);
  initStack(&resultStack);

  int len = strlen(expression);
  char tempResult[MAX];
  int tempIdx = 0;

  for (int i = 0; i < len; i++) {
    char c = expression[i];

    if (isNum(c)) {
      tempIdx = 0;
      while (i < len && isNum(expression[i])) {
        tempResult[tempIdx++] = expression[i];
        i++;
      }
      tempResult[tempIdx] = '\0';
      i--;
      pushStack(&resultStack, tempResult);
    } else if (c == '(') {
      char tempC[2] = {c, '\0'};
      pushStack(&operatorStack, tempC);
    } else if (c == ')') {
      while (strcmp(peekStack(&operatorStack), "(") != 0 &&
             operatorStack.idxTop >= 0) {
        char *op = popStack(&operatorStack);
        pushStack(&resultStack, op);
      }
      if (operatorStack.idxTop >= 0) {
        popStack(&operatorStack);
      }
    } else if (isOperator(c)) {
      char tempC[2] = {c, '\0'};
      while (operatorStack.idxTop >= 0 &&
             strcmp(peekStack(&operatorStack), "(") != 0 &&
             getPrecedence(peekStack(&operatorStack)) >= getPrecedence(tempC)) {
        char *op = popStack(&operatorStack);
        pushStack(&resultStack, op);
      }
      pushStack(&operatorStack, tempC);
    }
  }
  while (operatorStack.idxTop >= 0) {
    char *op = popStack(&operatorStack);
    pushStack(&resultStack, op);
  }
  postFixResult[0] = '\0';
  for (int i = 0; i <= resultStack.idxTop; i++) {
    strcat(postFixResult, resultStack.element[i]);
    if (i < resultStack.idxTop) {
      strcat(postFixResult, " ");
    }
  }
}

double evaluatePostFix(char *postFix) {
  double stack[MAX];
  int topIdx = -1;

  char *token = strtok(postFix, " ");
  while (token != NULL) {
    if (isValidDigit(token)) {
      stack[++topIdx] = atof(token);
    } else {
      double rightNum = stack[topIdx--];
      double leftNum = stack[topIdx--];
      double result;
      switch (token[0]) {
      case '+':
        result = leftNum + rightNum;
        break;
      case '-':
        result = leftNum - rightNum;
        break;
      case '*':
        result = leftNum * rightNum;
        break;
      case '/':
        result = leftNum / rightNum;
        break;
      case '^':
        result = 1;
        for (int i = 0; i < rightNum; i++)
          result *= leftNum;
        break;
      default:
        result = 0;
      }
      stack[++topIdx] = result;
    }
    token = strtok(NULL, " ");
  }
  return stack[topIdx];
}

void solve(char expression[]) {
  printf("Infix: %s\n", expression);

  char postFix[MAX];
  shuntingYard(expression, postFix);
  printf("Postfix: %s\n", postFix);

  char postFixCopy[MAX];
  strcpy(postFixCopy, postFix);

  double result = evaluatePostFix(postFixCopy);
  printf("Result: %f\n", result);
}

int main() {
  char expression[] = "(4.5*2)+2";
  solve(expression);
}
