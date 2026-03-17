-- Name: Kent Tran
-- CECS 342 Assignment 5
-- Algorithm: generic sorting Language: Haskell
-- Compiler: ghc
-- Editor: VSCode
-- Resources: https://www.geeksforgeeks.org/dsa/generic-implementation-of-quicksort-algorithm-in-c/

module Main where

import Data.List (sortBy)
import Data.Ord (comparing, Down(..))

data Person = Person { name :: String, age :: Int } deriving (Show)

numbers :: [Double]
numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]

people :: [Person]
people =
    [ Person "Hal"       20, Person "Susann"   31, Person "Dwight"    19
    , Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy"     22
    , Person "Cory"      27, Person "Mac"      19, Person "Romana"    27
    , Person "Doretha"   32, Person "Danna"    20, Person "Zara"      23
    , Person "Rosalyn"   26, Person "Risa"     24, Person "Benny"     28
    , Person "Juan"      33, Person "Natalie"  25
    ]

-- sort
sortedNumbers :: [Double]
sortedNumbers = sortBy compare numbers

sortedByName :: [Person]
sortedByName = sortBy (comparing name) people

sortedByAge :: [Person]
sortedByAge = sortBy (comparing (\p -> (Down (age p), name p))) people

-- print
printNumbers :: [Double] -> IO ()
printNumbers = mapM_ (\n -> putStrLn $ " " ++ show n)

printPeople :: [Person] -> IO ()
printPeople = mapM_ (\p -> putStrLn $ name p ++ ", " ++ show (age p))

main :: IO ()
main = do
    putStrLn "Numbers sorted ascending:"
    printNumbers sortedNumbers

    putStrLn "\nPeople sorted by name:"
    printPeople sortedByName

    putStrLn "\nPeople sorted by age (descending, then name):"
    printPeople sortedByAge