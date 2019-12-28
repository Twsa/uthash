b 43
r
define plist
	set $x=3
	while $x--
		p *head
		set head=(struct gree_ctrls *)head->hh->next
	end
end
document plist
	to list the list by travel
end
