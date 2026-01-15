----------
-- File Name : tb_Pattern_8_slv.vhd
-- Function : Test Bench for Pattern_8_slv.vhd
-- Author : Manabu Inoue
-- Rev and Date : 1.0 , 2008/10/19 , original source
----------


library IEEE;
use IEEE.std_logic_1164.all;

entity tb_Pattern_10_slv is
end tb_Pattern_10_slv;

architecture IO of tb_Pattern_10_slv is

	component Pattern_10_slv
	port (
		SW : in std_logic_vector(3 downto 0);
		SEG7 : out std_logic_vector(6 downto 0)
	);
	end component;

	signal done : boolean := false;
	signal sw : std_logic_vector(3 downto 0) := "0000";
	signal seg : std_logic_vector(6 downto 0);

begin

	SIM : Pattern_10_slv port map (
		SW => sw,
		SEG7 => seg
	);

	SIM_TIME : process
	begin
		wait for 1000 ns;
		done <= true;
		wait;
	end process;

	SWS : process
	begin
		if done = false then
			sw <= "0000";
			wait for 50 ns;
			sw <= "0001";
			wait for 50 ns;
			sw <= "0010";
			wait for 50 ns;
			sw <= "0011";
			wait for 50 ns;
			sw <= "0100";
			wait for 50 ns;
			sw <= "0101";
			wait for 50 ns;
			sw <= "0110";
			wait for 50 ns;
			sw <= "0111";
			wait for 50 ns;
			sw <= "1000";
			wait for 50 ns;
			sw <= "1001";
			wait for 50 ns;
		else
			wait;
		end if;
	end process;

end IO;