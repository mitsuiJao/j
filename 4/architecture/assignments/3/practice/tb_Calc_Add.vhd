----------
-- File Name : tb_Calc_Add.vhd
-- Function : Test Bench for Calc_Add.vhd
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;

entity tb_Calc_Add is
end tb_Calc_Add;

architecture IO of tb_Calc_Add is

	component Calc_Add
	port (
		INA : in integer range 0 to 3;
		INB : in integer range 0 to 3;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal done : boolean := false;
	signal ina : integer range 0 to 3 := 0;
	signal inb : integer range 0 to 3 := 0;
	signal seg7 : std_logic_vector(6 downto 0);

begin

	SIM : Calc_Add port map (
		INA => ina,
		INB => inb,
		SEG7 => seg7
	);

	SIM_TIME : process
	begin
		wait for 1000 ns;
		done <= true;
		wait;
	end process;

	INPUT_A : process
	begin
		if done = false then
			ina <= 0;
			wait for 50 ns;
			ina <= 1;
			wait for 50 ns;
			ina <= 2;
			wait for 50 ns;
			ina <= 3;
			wait for 50 ns;
		else
			wait;
		end if;
	end process;

	INPUT_B : process
	begin
		if done = false then
			inb <= 0;
			wait for 200 ns;
			inb <= 1;
			wait for 200 ns;
			inb <= 2;
			wait for 200 ns;
			inb <= 3;
			wait for 200 ns;
		else
			wait;
		end if;
	end process;

end IO;