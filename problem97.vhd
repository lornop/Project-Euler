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
        HEX0 : out std_logic_vector(7 downto 0);
        HEX1 : out std_logic_vector(7 downto 0);
        HEX2 : out std_logic_vector(7 downto 0);
        HEX3 : out std_logic_vector(7 downto 0);
        HEX4 : out std_logic_vector(7 downto 0);
        HEX5 : out std_logic_vector(7 downto 0)
        
    );
end entity Large_Non_Mersenne_Prime;

-- ----------------------------------------
-- Architecture: this is where the work happens
-- think of this like your main()
-- ----------------------------------------
architecture behavioral of Large_Non_Mersenne_Prime is

    -- internal signals go here
    -- think of these like your local variables
    signal exp      :   integer := 7830457;
    signal result   :   unsigned(39 downto 0) := to_unsigned(1, 40);
    signal base     :   unsigned(39 downto 0) := to_unsigned(2, 40);
    signal done     :   std_logic := '0';
    signal digit0   :   integer range 0 to 9;
    signal digit1   :   integer range 0 to 9;
    signal digit2   :   integer range 0 to 9;
    signal digit3   :   integer range 0 to 9;
    signal digit4   :   integer range 0 to 9;
    signal digit5   :   integer range 0 to 11;
    signal debounce :   integer := 500000;
    signal timer    :   integer := 0;
    signal display_upper : std_logic := '0';
    

begin

    process(clk, reset)
    begin
        
        if reset = '1' then     -- reset everything to initial values
            exp <= 7830457;
            result <= to_unsigned(1, 40);
            base <= to_unsigned(2, 40);
            done <= '0';

        elsif rising_edge(clk) then     -- main logic goes here
            if done = '0' then
                if (exp and 1) = 1 then
                result <= (result * base) mod 10000000000;
                end if;
            base <= (base * base) mod 10000000000;
            exp <= exp / 2;
            if exp / 2 = 0 then
                done <= '1';
                result <= ((result * 28433) + 1) mod 10000000000;
            end if;
                
            elsif done = '1' then
                if display_upper = '0' then
                    digit0 <= result mod 10;
                    digit1 <= result / 10 mod 10;
                    digit2 <= result / 100 mod 10;
                    digit3 <= result / 1000 mod 10;
                    digit4 <= result / 10000 mod 10;
                    digit5 <= 10;
                elsif display_upper = '1' then
                    digit0 <= result / 100000 mod 10;
                    digit1 <= result / 1000000 mod 10;
                    digit2 <= result / 10000000 mod 10;
                    digit3 <= result / 100000000 mod 10;
                    digit4 <= result / 1000000000 mod 10;
                    digit5 <= 11;
                end if;

                case digit0 is
                    when 0 => HEX0 <= "11000000";
                    when 1 => HEX0 <= "11111001";
                    when 2 => HEX0 <= "10100100";
                    when 3 => HEX0 <= "10110000";
                    when 4 => HEX0 <= "10011001";
                    when 5 => HEX0 <= "10010010";
                    when 6 => HEX0 <= "10000010";
                    when 7 => HEX0 <= "11111000";
                    when 8 => HEX0 <= "10000000";
                    when 9 => HEX0 <= "10010000";
                    when others => HEX0 <= "11111111";
                end case;
                case digit1 is
                    when 0 => HEX1 <= "11000000";
                    when 1 => HEX1 <= "11111001";
                    when 2 => HEX1 <= "10100100";
                    when 3 => HEX1 <= "10110000";
                    when 4 => HEX1 <= "10011001";
                    when 5 => HEX1 <= "10010010";
                    when 6 => HEX1 <= "10000010";
                    when 7 => HEX1 <= "11111000";
                    when 8 => HEX1 <= "10000000";
                    when 9 => HEX1 <= "10010000";
                    when others => HEX1 <= "11111111";
                end case;
                case digit2 is
                    when 0 => HEX2 <= "11000000";
                    when 1 => HEX2 <= "11111001";
                    when 2 => HEX2 <= "10100100";
                    when 3 => HEX2 <= "10110000";
                    when 4 => HEX2 <= "10011001";
                    when 5 => HEX2 <= "10010010";
                    when 6 => HEX2 <= "10000010";
                    when 7 => HEX2 <= "11111000";
                    when 8 => HEX2 <= "10000000";
                    when 9 => HEX2 <= "10010000";
                    when others => HEX2 <= "11111111";
                end case;
                case digit3 is
                    when 0 => HEX3 <= "11000000";
                    when 1 => HEX3 <= "11111001";
                    when 2 => HEX3 <= "10100100";
                    when 3 => HEX3 <= "10110000";
                    when 4 => HEX3 <= "10011001";
                    when 5 => HEX3 <= "10010010";
                    when 6 => HEX3 <= "10000010";
                    when 7 => HEX3 <= "11111000";
                    when 8 => HEX3 <= "10000000";
                    when 9 => HEX3 <= "10010000";
                    when others => HEX3 <= "11111111";
                end case;
                case digit4 is
                    when 0 => HEX4 <= "11000000";
                    when 1 => HEX4 <= "11111001";
                    when 2 => HEX4 <= "10100100";
                    when 3 => HEX4 <= "10110000";
                    when 4 => HEX4 <= "10011001";
                    when 5 => HEX4 <= "10010010";
                    when 6 => HEX4 <= "10000010";
                    when 7 => HEX4 <= "11111000";
                    when 8 => HEX4 <= "10000000";
                    when 9 => HEX4 <= "10010000";
                    when others => HEX4 <= "11111111";
                end case;
                case digit5 is
                    when 0 => HEX5 <= "11000000";
                    when 1 => HEX5 <= "11111001";
                    when 2 => HEX5 <= "10100100";
                    when 3 => HEX5 <= "10110000";
                    when 4 => HEX5 <= "10011001";
                    when 5 => HEX5 <= "10010010";
                    when 6 => HEX5 <= "10000010";
                    when 7 => HEX5 <= "11111000";
                    when 8 => HEX5 <= "10000000";
                    when 9 => HEX5 <= "10010000";
                    when 10 => HEX5 <= "01111111";
                    when others => HEX5 <= "11111111";
                end case;
            end if;
        end if;
    end process;

    process(clk, key0)
    begin
    if rising_edge(clk) then
        if key0 = '0' then
        timer <= timer + 1;
        elsif key0 = '1' then
            timer <= 0;
        end if;

        if timer = debounce then
            display_upper <= not display_upper;
            timer <= debounce;
        end if;
    end if;


    end process;


end behavioral;