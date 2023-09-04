main()
{
int i=0;
int k=0;
int j=0;
int l=0;

for(i=1; i<10; i++)
for(j=1; j<10; j++)
for (k=1; k<10; k++)
for(l=0; l<1; l++)
printf("mac-trace line-card 9 ingress 1 egress 2 non-vscale cvlan 1 svlan 1001 00:00:%02x:%02x:%02x:%02x 00:b0:%02x:%02x:%02x:%02x switch-chip\r\n", i, j, k,l,l,k, j, i);

}
