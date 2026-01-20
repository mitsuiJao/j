----------
-- File Name : tb_UDcnt_Disp.vhd
-- Function : Test Bench for UDcnt_Disp.vhd
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2025/01/20 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;

entity tb_UDcnt_Disp is
end tb_UDcnt_Disp;

architecture IO of tb_UDcnt_Disp is

	component UDcnt_Disp
	port (
		CLK : in std_logic;
		RST : in std_logic;
		UDS : in std_logic;
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal done : boolean := false;
	signal clk : std_logic := '0';
	signal rst : std_logic := '0';
	signal uds : std_logic := '0';
	signal seg7 : std_logic_vector(6 downto 0);

begin

	SIM : UDcnt_Disp port map (
		CLK => clk,
		RST => rst,
		UDS => uds,
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

	INPUT_UDS : process
	begin
		if done = false then
			uds <= '0';
			wait for 500 ns;
			uds <= '1';
			wait for 500 ns;
		else
			wait;
		end if;
	end process;

end IO;