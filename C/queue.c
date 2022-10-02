#include <stdio.h>

int queue[100];
int front = -1, rear = -1;

void enqueue(int val) {
  if (rear == 99)
    printf("\nOVERFLOW!!");
  else {
    if (front == -1 && rear == -1)
      front = rear = 0;
    else
      rear++;
    queue[rear] = val;
  }
}

int dequeue() {
  int val;
  if (front == -1 || front > rear) {
    printf("UNDERFLOW!!\n");
    return -1;
  } else {
    val = queue[front];
    front++;
    if (front > rear) {
      front = rear = -1;
    }
    return val;
  }
}

int getfront() {
  int val;
  if (front == -1 || front > rear) {
    printf("UNDERFLOW!!\n");
    return -1;
  } else {
    val = queue[front];
  }
  return val;
}

int getrear() {
  int val;
  if (front == -1 || front > rear) {
    printf("UNDERFLOW!!\n");
    return -1;
  } else {
    val = queue[rear];
  }
  return val;
}

int size() {
  int val = 0;
  for (int i = front; i <= rear; i++)
    val++;

  return val;
}

void display() {
  if (front == -1)
    printf("Queue is EMPTY");
  else {
    for (int i = front; i <= rear; i++)
      printf("\t%d", queue[i]);
  }
}

int main(void) {
  int chs, val, values;

  do {
    printf("\n\t\t\t\tMENU\n");
    printf("\n1.Enqueue\n2.Dequeue\n3.Get Front\n4.Get "
           "Rear\n5.Size\n6.Display\n7.Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &chs);

    switch (chs) {
    case 1:
      printf("\nEnter the value to be enqueue: ");
      scanf("%d", &val);
      enqueue(val);
      break;
    case 2:

      values = dequeue();
      printf("Value dequeued: %d", values);
      /*if (front != -1)
        printf("The value dequeue is %d", values);*/
      break;
    case 3:
      values = getfront();
      printf("Value at front: %d", values);
      break;
    case 4:
      values = getrear();
      printf("Value at rear: %d", values);
      break;
    case 5:
      values = size();
      printf("Size of Queue is %d", values);
      break;
    case 6:
      display();
      break;
    }

  } while (chs != 7);

  return 0;
}
