void Choose(char str[], int counter)
{
    for(int i = 0; i < counter; i++)
    {
        int min = i;
        for(int j = i; j < counter; j++)
        {
            if(str[j] < str[min])
            {
                min = j;
            }
        }
        int temp = str[i];
        str[i] = str[min];
        str[min] = temp;
    }
}

void Bubble(char str[], int counter)
{
  //Циклічний прохід по масиву
  for(int k = 0; k < counter - 1; k++)
  {
    int swaps = 0;

    for(int i = 0; i < counter - 1 - k; i++)
    {
        if(str[i] > str[i+1])
        {
          int temp = str[i+1];
          str[i+1] = str[i];
          str[i] = temp;
          swaps++;
        }
      }
    if(!swaps)
    break;
  }
}


void IncludeSort(char str[], int counter)
{

  for (int i = 1; i < counter; i++)
  {
    int value = str[i]; 
    int index = i;     
    while ((index > 0) && (str[index - 1] > value))
    {  
      str[index] = str[index - 1];
      index--;   
    }
    str[index] = value; 
  }
}
