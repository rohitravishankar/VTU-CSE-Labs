//C program to implement Bankers Algorithm to avoid deadlock
#include<stdio.h>
void
main ()
{
  int clm[7][5], req[7][5], alloc[7][5], rsrc[5], avail[5], comp[7], work[5],
    flag[7], safe[7];
  int p, r, i, j, prc, count, t, k, x;

  count = 0;


  printf ("Enter the no of processes:\n");
  scanf ("%d", &p);

  for (i = 0; i < p; i++)
    comp[i] = 0;
  printf ("Enter the no of resources:\n");
  scanf ("%d", &r);

  printf ("Enter the claim for each process:");
  for (i = 0; i < p; i++)
    {
      printf ("\nFor process %d", i);
      for (j = 0; j < r; j++)
	{
	  scanf ("%d", &clm[i][j]);
	}
    }
  printf ("Enter the allocation for each process:\n");

  for (i = 0; i < p; i++)
    {
      printf ("\nFor process ", i);
      for (j = 0; j < r; j++)
	{
	  scanf ("%d", &alloc[i][j]);
	}
    }
  printf ("Enter total no of each resource:");
  for (j = 0; j < r; j++)
    scanf ("%d", &rsrc[j]);

  for (j = 0; j < r; j++)
    {
      int total = 0;
      avail[j] = 0;
      for (i = 0; i < p; i++)
	{
	  total += alloc[i][j];
	}
      avail[j] = rsrc[j] - total;
    }


  for (i = 0; i < p; i++)
    {
      for (j = 0; j < r; j++)
	{
	  req[i][j] = clm[i][j] - alloc[i][j];
	}
    }

  printf ("\n\nAvailable resorces is:");

  for (j = 0; j < r; j++)
    {
      work[j] = avail[j];
      printf ("%d\t ", avail[j]);
    }

  printf ("\nClaim matrix:\t\tAllocation matrix:\t\t need matrix\n");

  for (i = 0; i < p; i++)
    {

      for (j = 0; j < r; j++)
	{
	  printf ("%d ", clm[i][j]);
	}
      printf ("\t\t\t");

      for (j = 0; j < r; j++)
	{
	  printf ("%d ", alloc[i][j]);

	}
      printf ("\t\t\t");
      for (j = 0; j < r; j++)
	{
	  printf ("%d ", req[i][j]);
	}

      printf ("\n");
    }


  k = 0;
  x = 0;
  do
    {
      k++;
      for (i = 0; i < p; i++)
	flag[i] = 0;
      for (i = 0; i < p; i++)
	{
	  if (comp[i] == 0)
	    {

	      for (j = 0; j < r; j++)
		{
		  if (req[i][j] > work[j])
		    {
		      flag[i] = 1;
		      break;
		    }
		}

	      if (flag[i] == 0)
		{
		  for (j = 0; j < r; j++)
		    {
		      work[j] = work[j] + alloc[i][j];
		    }
		  comp[i] = 1;
		  ++count;
		  safe[x] = i;
		  x++;
		}

	    }

	}


    }
  while (count != p && k < p);



  if (count == p)
    {
      printf ("\nThe system is in a safe state!!\n the safe sequence is \n");
      for (i = 0; i < p; i++)
	{
	  printf ("p%d ", safe[i]);
	}
    }

  else

    printf ("\nThe system is in an unsafe state!!");



}
