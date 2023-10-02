#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int ay[], int length)
{
    bool swapped = false;
    int i = 0;

    do
    {
        swapped = false;

        for (int j = 0; j < (length - 1 - i); j++)
        {

            if (ay[j] > ay[j + 1])
            {
                swap(&ay[j], &ay[j+1]);
                swapped = true;
            }
        }
        i++;
    } while (swapped);
}

void selection_sort(int ax[], int length) {

    int min;
    for (int i = 0; i < length - 1; i++) {
        min = i;
        for (int j = i + 1; j < length; j++) {
            if (ax[j] < ax[min]) {
                min = j;
            }
        }

        if (min != i) 
        { 
            swap(&ax[min], &ax[i]);
        }
    }
}

void insertionSort(int arr[], int n)

{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high)
{
 
    int pivot = arr[high];


    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {


        if (arr[j] < pivot) {


            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high) {

    
        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main()
{   
    // 288 -122 -293 117 -85 183 324 -403 -148 357 419 -320 -171 -194 422 -389 441 153 121 241 -87 139 -147 251 -371 -12 -420 -400 302 -193 162 -487 145 -387 218 61 27 342 -365 -266 -50 -426 203 101 219 -161 -412 466 124 -251 -315 -361 -89 -67 -419 -252 -17 460 138 354 -208 469 -475 -495 113 174 -176 86 405 -382 67 71 135 254 -405 476 267 -396 -260 69 209 258 -464 174 4 387 494 -92 -308 270 29 379 -80 -363 62 -287 158 113 160 113 -33 -96 84 294 -28 -62 -35 -148 274 259 203 340 195 485 333 334 463 -333 -454 179 409 451 -401 -451 356 -412 -354 327 -412 485 215 8 -175 -376 -190 -217 -451 280 43 -287 -500 396 463 -328 -250 265 381 -39 -261 -276 443 -333 -414 147 -306 447 123 -238 70 114 435 -38 374 194 412 -17 -432 46 -313 90 -414 -483 -176 293 -66 45 407 162 148 -493 179 -305 -402 -157 281 -21 38 412 -422 493 43 159 -334 -344 365 -177 -276 -260 -415 -456 -317 -412 -490 -398 91 367 125 -152 -93 237 -275 252 39 -363 -41 -157 -45 217 -374 214 250 410 -442 384 -149 287 -452 -43 348 157 322 389 -154 172 190 168 208 -355 -184 -196 219 -46 105 -329 -95 -182 288 272 -326 -392 -443 -190 240 212 -144 -466 -204 302 67 147 -197 -445 10 164 124 -120 446 3 -8 353 -202 -227 406 -308 -240 -21 160 -454 135 -209 -1 -333 -247 430 152 281 289 -152 -24 -238 92 -359 -40 76 -210 384 -234 257 -36 437 -487 -123 53 156 -76 -494 -264 224 -364 -17 23 318 104 -64 -415 -327 227 49 -474 -277 274 330 55 369 319 499 326 375 -86 -332 -5 153 150 -74 198 -492 183 247 -477 483 424 424 -106 37 -48 1 438 249 32 -157 263 -312 -135 81 335 439 -372 317 -211 389 261 50 -162 352 437 46 251 -193 199 47 32 -156 -143 133 -373 326 -498 -285 141 3 119 105 -486 -125 -191 161 161 93 -138 -230 -70 349 -425 143 13 293 -60 -301 -189 -69 173 311 363 -193 132 244 487 -40 -273 388 -255 489 282 -397 -80 204 -301 66 -125 -273 -500 -201 -397 204 -368 -199 -379 -330 320 364 360 -482 -364 77 -138 -2 -318 -436 -299 -196 22 -428 -451 465 -178 -202 468 -417 23 -305 110 404 -206 -92 -471 -353 -403 -172 282 109 -452 425 14 80 -333 383 349 -206 -226 129 366 -326 89 293 296 206 -222 -27 431 276 115 -318 125 -160 -101 -191 147 -385 -71 -121 -360 -23 -27 14 229 -20 408 121 -23 -405

   
    int a[500];
    int length;

    printf("Enter the length: ");
    scanf_s("%d", &length); // Note the & before length to get its address

    for (int i = 0; i < length; i++) {
        scanf_s("%d", &a[i]); // Note the & before a[i] to get the address of the element
    }

    int *a1 = (int*)malloc(length * sizeof(int));
    int* a2 = (int*)malloc(length * sizeof(int));
    int* a3 = (int*)malloc(length * sizeof(int));
    int* a4 = (int*)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        a1[i] = a[i];
        a2[i] = a[i];
        a3[i] = a[i];
        a4[i] = a[i];
    }

    double time1 = clock();
    bubble_sort(a1, length);
    double time_taken1 = (double)(clock() - time1) / CLOCKS_PER_SEC;

    double time2 = clock();
    selection_sort(a2, length);
    double time_taken2 = (double)(clock() - time2) / CLOCKS_PER_SEC;

    double time3 = clock();
    insertionSort(a3, length);
    double time_taken3 = (double)(clock() - time3) / CLOCKS_PER_SEC;

    double time4 = clock();
    insertionSort(a4, length);
    double time_taken4 = (double)(clock() - time4) / CLOCKS_PER_SEC;

    quickSort(a4, 0, length - 1);

    for (int i = 0; i < length; i++) {
        printf("a1[%d] = %d\n", i, a1[i]);
    }
    printf("Time taken: %f\n", time_taken1);

    for (int i = 0; i < length; i++) {
        printf("a2[%d] = %d\n", i, a2[i]);
    }
    printf("Time taken: %f\n", time_taken2);

    for (int i = 0; i < length; i++) {
        printf("a3[%d] = %d\n", i, a3[i]);
    }
    printf("Time taken: %f\n", time_taken3);
    
    for (int i = 0; i < length; i++) {
        printf("a4[%d] = %d\n", i, a4[i]);
    }
    printf("Time taken: %f\n", time_taken4);

    free(a1);
    free(a2);
    free(a3);
    free(a4);
    return 0;
}
