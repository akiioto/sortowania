#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include <stdlib.h>
#include <iostream>


using namespace sf;
using namespace std;

void bubbleSort( int size, VertexArray rectang, RenderWindow &thatWindow, int windowWidth)
{
    thatWindow.setFramerateLimit(60);

    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setString("Bubble sort ");
    text.setCharacterSize(24);
    text.move(550.f,800.f);
    float array[size];
    int rectangWidth = (int)(windowWidth - 20 - size) / size ;
    for (int i = 0; i < size; i++)
        array[i] = rand() % 700 + 10;

    for (int i = 0; i < size; i++)
    {
        rectang[i * 4].color = Color::White;
        rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 1].color = Color::White;
        rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 2].color = Color::White;
        rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
        rectang[i * 4 + 3].color = Color::White;
        rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
    }

    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                // swap if greater is at the rear position
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                rectang[i * 4].color = Color::White;
                rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i, 750 - array[i]);
                rectang[i * 4 + 1].color = Color::White;
                rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750 - array[i]);
                rectang[i * 4 + 2].color = Color::White;
                rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
                rectang[i * 4 + 3].color = Color::White;
                rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);

                rectang[(i + 1) * 4].color = Color::Red;
                rectang[(i + 1) * 4].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
                rectang[(i + 1) * 4 + 1].color = Color::Red;
                rectang[(i + 1) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
                rectang[(i + 1) * 4 + 2].color = Color::Red;
                rectang[(i + 1) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750);
                rectang[(i + 1) * 4 + 3].color = Color::Red;
                rectang[(i + 1) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750);

                thatWindow.clear();
                thatWindow.draw(rectang);
                thatWindow.draw(text);
                thatWindow.display();

                rectang[(i + 1) * 4].color = Color::White;
                rectang[(i + 1) * 4 + 1].color = Color::White;
                rectang[(i + 1) * 4 + 2].color = Color::White;
                rectang[(i + 1) * 4 + 3].color = Color::White;
            }
        }
    }
    sf::sleep(sf::seconds(3));
}

void insertionSort(int size, VertexArray rectang, RenderWindow &thatWindow, int windowWidth)
{
    thatWindow.setFramerateLimit(60);
    int rectangWidth = (int)(windowWidth - 20 - size) / size ;
    float array[size];
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setString("Insertion sort ");
    text.setCharacterSize(24);
    text.move(550.f,800.f);
    for (int i = 0; i < size; i++)
        array[i] = rand() % 700 + 10;

    for (int i = 0; i < size; i++)
    {
        rectang[i * 4].color = Color::White;
        rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 1].color = Color::White;
        rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 2].color = Color::White;
        rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
        rectang[i * 4 + 3].color = Color::White;
        rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
    }

    int key, j;
    for(int i = 1; i<=size; i++)
    {
        key = array[i];//take value
        j = i;
        while(j > 0 && array[j-1]>key)
        {
            array[j] = array[j-1];
            rectang[(j) * 4].color = Color::Red;
            rectang[(j) * 4].position = sf::Vector2f(10.f + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 1].color = Color::Red;
            rectang[(j) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 2].color = Color::Red;
            rectang[(j) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750);
            rectang[(j) * 4 + 3].color = Color::Red;
            rectang[(j) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * j + j, 750);
            thatWindow.clear();
            thatWindow.draw(rectang);
            thatWindow.draw(text);
            thatWindow.display();
            j--;
        }
        j = i;

        while(j > 0 && array[j-1]>key)
        {
            j--;
            rectang[(j) * 4].color = Color::White;
            rectang[(j) * 4].position = sf::Vector2f(10.f + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 1].color = Color::White;
            rectang[(j) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 2].color = Color::White;
            rectang[(j) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750);
            rectang[(j) * 4 + 3].color = Color::White;
            rectang[(j) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * j + j, 750);
        }
        thatWindow.clear();
        thatWindow.draw(rectang);
        thatWindow.draw(text);
        thatWindow.display();

        array[j] = key;   //insert in right place

        for( int k = 0; k < j; k++)
        {
            rectang[k * 4].color = Color::White;
            rectang[k * 4].position = sf::Vector2f(10.f + rectangWidth * k + k, 750 - array[k]);
            rectang[k * 4 + 1].color = Color::White;
            rectang[k * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * k + k, 750 - array[k]);
            rectang[k * 4 + 2].color = Color::White;
            rectang[k * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * k + k, 750);
            rectang[k * 4 + 3].color = Color::White;
            rectang[k * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * k + k, 750);
        }
        thatWindow.clear();
        thatWindow.draw(rectang);
        thatWindow.draw(text);
        thatWindow.display();
    }
    sf::sleep(sf::seconds(3));
}

void selectionSort(int size, VertexArray rectang, RenderWindow &thatWindow, int windowWidth)
{
    int i, j, min_idx;
    float array[size],temp;
    thatWindow.setFramerateLimit(60);
    int rectangWidth = (int)(windowWidth - 20 - size) / size ;
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setString("Selection sort ");
    text.setCharacterSize(24);
    text.move(550.f,800.f);
    for (i = 0; i < size; i++)
        array[i] = rand() % 700 + 10;

    for (int i = 0; i < size; i++)
    {
        rectang[i * 4].color = Color::White;
        rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 1].color = Color::White;
        rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 2].color = Color::White;
        rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
        rectang[i * 4 + 3].color = Color::White;
        rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
    }
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
            rectang[(j) * 4].color = Color::Red;
            rectang[(j) * 4].position = sf::Vector2f(10.f + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 1].color = Color::Red;
            rectang[(j) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 2].color = Color::Red;
            rectang[(j) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750);
            rectang[(j) * 4 + 3].color = Color::Red;
            rectang[(j) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * j + j, 750);

            thatWindow.clear();
            thatWindow.draw(rectang);
            thatWindow.draw(text);
            thatWindow.display();

            rectang[(j) * 4].color = Color::White;
            rectang[(j) * 4].position = sf::Vector2f(10.f + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 1].color = Color::White;
            rectang[(j) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750 - array[j]);
            rectang[(j) * 4 + 2].color = Color::White;
            rectang[(j) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750);
            rectang[(j) * 4 + 3].color = Color::White;
            rectang[(j) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * j + j, 750);
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
        rectang[i * 4].color = Color::White;
        rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 1].color = Color::White;
        rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 2].color = Color::White;
        rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
        rectang[i * 4 + 3].color = Color::White;
        rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);

        rectang[min_idx * 4].color = Color::White;
        rectang[min_idx * 4].position = sf::Vector2f(10.f + rectangWidth * min_idx + min_idx,750 -  array[i]);
        rectang[min_idx * 4 + 1].color = Color::White;
        rectang[min_idx * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * min_idx + min_idx,750 -  array[i]);
        rectang[min_idx * 4 + 2].color = Color::White;
        rectang[min_idx * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * min_idx + min_idx, 750);
        rectang[min_idx * 4 + 3].color = Color::White;
        rectang[min_idx * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * min_idx + min_idx, 750);
        thatWindow.clear();
        thatWindow.draw(rectang);
        thatWindow.draw(text);
        thatWindow.display();
    }
    sf::sleep(sf::seconds(3));
}

void merge(float array[], int l, int m, int r, VertexArray rectang, RenderWindow &thatWindow, int windowWidth, int rectangWidth, int size)
{
    thatWindow.setFramerateLimit(60);
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setString("Merge sort ");
    text.setCharacterSize(24);
    text.move(550.f,800.f);
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* create temp arrays */
    float L[n1], R[n2];
    for (int i = 0; i < size; i++)
    {
        rectang[i * 4].color = Color::White;
        rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 1].color = Color::White;
        rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 2].color = Color::White;
        rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
        rectang[i * 4 + 3].color = Color::White;
        rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
    }
    thatWindow.clear();
    thatWindow.draw(rectang);
    thatWindow.draw(text);
    thatWindow.display();

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1+ j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
        thatWindow.clear();
        thatWindow.draw(rectang);
        thatWindow.draw(text);
        thatWindow.display();
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
    for(i = l; i < r; i++)
    {
        rectang[( i) * 4].color = Color::Red;
        rectang[( i) * 4].position = sf::Vector2f(10.f + rectangWidth * ( i) + i,750 -  array[i]);
        rectang[( i) * 4 + 1].color = Color::Red;
        rectang[( i) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * ( i) + i,750 -  array[i]);
        rectang[( i) * 4 + 2].color = Color::Red;
        rectang[( i) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * ( i) + i, 750);
        rectang[( i) * 4 + 3].color = Color::Red;
        rectang[( i) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * ( i) + i, 750);
        thatWindow.clear();
        thatWindow.draw(rectang);
        thatWindow.draw(text);
        thatWindow.display();
    }
}


void mergeSort(float array[], int size, int l, int r, VertexArray rectang, RenderWindow &thatWindow, int windowWidth)
{
    int rectangWidth = (int)(windowWidth - 20 - size) / size ;
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(array, size, l, m, rectang, thatWindow, windowWidth);
        mergeSort(array, size, m+1, r, rectang, thatWindow, windowWidth);
        merge(array, l, m, r, rectang, thatWindow, windowWidth, rectangWidth, size);
    }
}

void cocktailSort(int size, VertexArray rectang, RenderWindow &thatWindow, int windowWidth)
{
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setString("Cocktail sort ");
    text.setCharacterSize(24);
    text.move(550.f,800.f);
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    thatWindow.setFramerateLimit(60);
    int rectangWidth = (int)(windowWidth - 20 - size) / size ;
    float array[size];

    for (int i = 0; i < size; i++)
        array[i] = rand() % 700 + 10;

    for (int i = 0; i < size; i++)
    {
        rectang[i * 4].color = Color::White;
        rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 1].color = Color::White;
        rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 2].color = Color::White;
        rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
        rectang[i * 4 + 3].color = Color::White;
        rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
    }

    while (swapped)
    {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;
        float temp;
        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                rectang[i * 4].color = Color::Red;
                rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
                rectang[i * 4 + 1].color = Color::Red;
                rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
                rectang[i * 4 + 2].color = Color::Red;
                rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
                rectang[i * 4 + 3].color = Color::Red;
                rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);

                rectang[(i + 1) * 4].color = Color::Red;
                rectang[(i + 1) * 4 ].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
                rectang[(i + 1) * 4 + 1].color = Color::Red;
                rectang[(i + 1) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
                rectang[(i + 1) * 4 + 2].color = Color::Red;
                rectang[(i + 1) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750);
                rectang[(i + 1) * 4 + 3].color = Color::Red;
                rectang[(i + 1) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750);

                swapped = true;
            }
            thatWindow.clear();
            thatWindow.draw(rectang);
            thatWindow.draw(text);
            thatWindow.display();
            rectang[i * 4].color = Color::White;
            rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
            rectang[i * 4 + 1].color = Color::White;
            rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
            rectang[i * 4 + 2].color = Color::White;
            rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
            rectang[i * 4 + 3].color = Color::White;
            rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
            rectang[(i + 1) * 4].color = Color::White;
            rectang[(i + 1) * 4 ].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
            rectang[(i + 1) * 4 + 1].color = Color::White;
            rectang[(i + 1) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
            rectang[(i + 1) * 4 + 2].color = Color::White;
            rectang[(i + 1) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750);
            rectang[(i + 1) * 4 + 3].color = Color::White;
            rectang[(i + 1) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750);
        }

        // if nothing moved, then array is sorted.
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;

        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                rectang[i * 4].color = Color::Red;
                rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
                rectang[i * 4 + 1].color = Color::Red;
                rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
                rectang[i * 4 + 2].color = Color::Red;
                rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
                rectang[i * 4 + 3].color = Color::Red;
                rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);

                rectang[(i + 1) * 4].color = Color::Red;
                rectang[(i + 1) * 4 ].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
                rectang[(i + 1) * 4 + 1].color = Color::Red;
                rectang[(i + 1) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
                rectang[(i + 1) * 4 + 2].color = Color::Red;
                rectang[(i + 1) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750);
                rectang[(i + 1) * 4 + 3].color = Color::Red;
                rectang[(i + 1) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750);

                swapped = true;
            }
            thatWindow.clear();
            thatWindow.draw(rectang);
            thatWindow.draw(text);
            thatWindow.display();

            rectang[i * 4].color = Color::White;
            rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
            rectang[i * 4 + 1].color = Color::White;
            rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
            rectang[i * 4 + 2].color = Color::White;
            rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
            rectang[i * 4 + 3].color = Color::White;
            rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
            rectang[(i + 1) * 4].color = Color::White;
            rectang[(i + 1) * 4 ].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
            rectang[(i + 1) * 4 + 1].color = Color::White;
            rectang[(i + 1) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
            rectang[(i + 1) * 4 + 2].color = Color::White;
            rectang[(i + 1) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750);
            rectang[(i + 1) * 4 + 3].color = Color::White;
            rectang[(i + 1) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750);
        }

        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
    sf::sleep(sf::seconds(3));
}

int partition (float array[], int low, int high, VertexArray rectang, RenderWindow &thatWindow, int windowWidth, int size, int rectangWidth)
{
    thatWindow.setFramerateLimit(60);
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setString("Quick sort");
    text.setCharacterSize(24);
    text.move(550.f,800.f);
    float temp;
    int pivot = array[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    for (int i = 0; i < size; i++)
    {
        rectang[i * 4].color = Color::White;
        rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 1].color = Color::White;
        rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i,750 -  array[i]);
        rectang[i * 4 + 2].color = Color::White;
        rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
        rectang[i * 4 + 3].color = Color::White;
        rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);
    }
    thatWindow.clear();
    thatWindow.draw(rectang);
    thatWindow.draw(text);
    thatWindow.display();
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            rectang[i * 4].color = Color::Red;
            rectang[i * 4].position = sf::Vector2f(10.f + rectangWidth * i + i, 750 - array[i]);
            rectang[i * 4 + 1].color = Color::Red;
            rectang[i * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750 - array[i]);
            rectang[i * 4 + 2].color = Color::Red;
            rectang[i * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * i + i, 750);
            rectang[i * 4 + 3].color = Color::Red;
            rectang[i * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * i + i, 750);

            rectang[j * 4].color = Color::Red;
            rectang[j * 4].position = sf::Vector2f(10.f + rectangWidth * j + j, 750 - array[j + 1]);
            rectang[j * 4 + 1].color = Color::Red;
            rectang[j * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750 - array[j + 1]);
            rectang[j * 4 + 2].color = Color::Red;
            rectang[j * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * j + j, 750);
            rectang[j * 4 + 3].color = Color::Red;
            rectang[j * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * j + j, 750);
            thatWindow.clear();
            thatWindow.draw(rectang);
            thatWindow.draw(text);
            thatWindow.display();
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    rectang[(i + 1) * 4].color = Color::Red;
    rectang[(i + 1) * 4].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
    rectang[(i + 1) * 4 + 1].color = Color::Red;
    rectang[(i + 1) * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750 - array[i + 1]);
    rectang[(i + 1) * 4 + 2].color = Color::Red;
    rectang[(i + 1) * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * (i + 1) + i + 1, 750);
    rectang[(i + 1) * 4 + 3].color = Color::Red;
    rectang[(i + 1) * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * (i + 1) + i + 1, 750);

    rectang[high * 4].color = Color::Red;
    rectang[high * 4].position = sf::Vector2f(10.f + rectangWidth * high + high, 750 - array[high]);
    rectang[high * 4 + 1].color = Color::Red;
    rectang[high * 4 + 1].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * high + high, 750 - array[high]);
    rectang[high * 4 + 2].color = Color::Red;
    rectang[high * 4 + 2].position = sf::Vector2f((10.f + rectangWidth) + rectangWidth * high + high, 750);
    rectang[high * 4 + 3].color = Color::Red;
    rectang[high * 4 + 3].position = sf::Vector2f(10.f + rectangWidth * high + high, 750);
    thatWindow.clear();
    thatWindow.draw(rectang);
    thatWindow.draw(text);
    thatWindow.display();
    return (i + 1);
}


void quickSort(float array[], int low, int high, VertexArray rectang, RenderWindow &thatWindow, int windowWidth, int size)
{
    int rectangWidth = (int)(windowWidth - 20 - size) / size ;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(array, low, high, rectang, thatWindow, windowWidth, size, rectangWidth);
        // Separately sort elements before
        // partition and after partition
        quickSort(array, low, pi - 1, rectang, thatWindow, windowWidth, size);
        quickSort(array, pi + 1, high, rectang, thatWindow, windowWidth, size);
    }
}

int main()
{
    int windowWidth = 1280,windowheightValue = 900;
    RenderWindow window(VideoMode(windowWidth, windowheightValue), "SFML works!");
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setString("1: Bubble sort \n2: Insertion sort \n3: Selection sort\n4: Merge sort\n5: Cocktail sort\n6: Quick sort \nESC: exit");
    text.setCharacterSize(24);
    window.setActive();
    window.setFramerateLimit(25);

    srand (time(NULL));
    int odstep = 0, odstep2 = 0;
    const int rectangleNumber = 150;
    VertexArray rectang(Quads, 9999);

    while (window.isOpen())
    {
        Event ev;
        while (window.pollEvent(ev))
        {

            if(ev.type == sf::Event::Closed)
            {
                window.close();
            }
            if(ev.type == sf::Event::KeyPressed)
            {
                switch(ev.key.code)
                {
                case(sf::Keyboard::Escape):
                    window.close();
                    break;

                case(sf::Keyboard::Num1):
                    bubbleSort(100,rectang,window,windowWidth);
                    break;

                case(sf::Keyboard::Num2):
                    insertionSort(100, rectang, window, windowWidth);
                    break;

                case(sf::Keyboard::Num3):
                    selectionSort(100, rectang, window, windowWidth);
                    break;

                case(sf::Keyboard::Num4):
                {
                    int size = 100;
                    float array[size];
                    for (int i = 0; i < size; i++)
                        array[i] = rand() % 700 + 10;
                    mergeSort(array, size, 0, size, rectang, window, windowWidth);
                    break;
                }

                case(sf::Keyboard::Num5):
                {
                    cocktailSort(100, rectang, window, windowWidth);
                    break;
                }
                case(sf::Keyboard::Num6):
                {
                    int size = 200;
                    float array[size];
                    for (int i = 0; i < size; i++)
                        array[i] = rand() % 700 + 10;
                    quickSort(array, 0, size, rectang, window, windowWidth, size);
                    break;
                }
                }
            }
            window.clear();
            window.draw(text);
            window.display();
        }
    }
    return 0;
}
