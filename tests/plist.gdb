b 154
r
set print pretty off
define plist
	set $x=48
	while $x--
		p *head
		set head=(struct gree_ctrls *)head->hh->next
	end
end
document plist
	to list the list by travel
end
