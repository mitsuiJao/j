----------
-- File Name : tb_Counter_Disp.vhd
-- Function : Test Bench for Counter_Disp.vhd
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/11/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;

entity tb_Counter_Disp is
end tb_Counter_Disp;

architecture IO of tb_Counter_Disp is

	component Counter_Disp
	port (
		CLK : in std_logic;
		RST : in std_logic;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal done : boolean := false;
	signal clk : std_logic := '0';
	signal rst : std_logic := '0';
	signal seg7 : std_logic_vector(6 downto 0);

begin

	SIM : Counter_Disp port map (
		CLK => clk,
		RST => rst,
		SEG7 => seg7
	);

	SIM_TIME : process
	begin
		wait for 1000 ns;
		done <= true;
		wait;
	end process;

	INPUT_CLK : process
	begin
		if done = false then
			clk <= '0';
			wait for 10 ns;
			clk <= '1';
			wait for 10 ns;
		else
			wait;
		end if;
	end process;

	INPUT_RST : process
	begin
		if done = false then
			rst <= '0';
			wait for 330 ns;
			rst <= '1';
			wait for 30 ns;
		else
			wait;
		end if;
	end process;

end IO;