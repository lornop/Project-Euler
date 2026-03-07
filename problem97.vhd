-- ----------------------------------------
-- Project: Project Euler Problem 97
-- Description: I got the template from claude to help me do some more vhdl. probably end up getting more help from ai, so this isnt all me
-- Large Non-Mersenne Prime
-- Problem 97

-- The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593 − 1; 
-- it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p − 1, have been found which contain more digits.

-- However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits:
-- 28433 × 2^7830457 + 1.

-- Find the last ten digits of this prime number.
-- ----------------------------------------

-- Libraries
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

-- ----------------------------------------
-- Entity: defines the inputs and outputs
-- think of this like your function prototype
-- what goes in, what comes out
-- ----------------------------------------
entity Large_Non_Mersenne_Prime is
    port(
        clk     : in std_logic;   -- clock
        reset   : in std_logic;   -- reset
        key0    : in std_logic;   -- push button
        HEX0 : out std_logic_vector(6 downto 0);
        HEX1 : out std_logic_vector(6 downto 0);
        HEX2 : out std_logic_vector(6 downto 0);
        HEX3 : out std_logic_vector(6 downto 0);
        HEX4 : out std_logic_vector(6 downto 0);
        HEX5 : out std_logic_vector(6 downto 0)
    );
end entity Large_Non_Mersenne_Prime;

-- ----------------------------------------
-- Architecture: this is where the work happens
-- think of this like your main()
-- ----------------------------------------
architecture behavioral of Large_Non_Mersenne_Prime is

    -- internal signals go here
    -- think of these like your local variables

begin

    -- ----------------------------------------
    -- Sequential process: things that happen on clock edges
    -- think of this like your loops and state changes
    -- ----------------------------------------
    process(clk, reset)
    begin
        if reset = '1' then
            -- reset everything to initial values

        elsif rising_edge(clk) then
            -- main logic goes here

        end if;
    end process;

    -- ----------------------------------------
    -- Combinational logic goes outside the process
    -- think of this like expressions that are always true
    -- wires rather than registers
    -- ----------------------------------------

end behavioral;