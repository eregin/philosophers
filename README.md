<section class="u-clearfix current-section u-block-f300-1" custom-posts-hash="[]" data-style="blank" data-section-properties="{&quot;margin&quot;:&quot;none&quot;,&quot;stretch&quot;:true}" id="sec-49bf" data-source="Blank" data-id="f300" style="">
  <div class="u-clearfix u-sheet u-valign-middle u-block-f300-2" style="min-height: 800px" data-block-type="Sheet"><h1 class="u-text u-text-default u-block-control u-align-center u-title u-block-f300-8" data-block="29" style="margin: 0px auto; font-size: 3rem;" data-block-type="Text">Philoso​phers</h1><blockquote class="u-text u-text-default u-block-control u-align-center u-block-f300-9" data-block="30" style="margin-top: 0px; margin-bottom: 0px; margin-left: auto; margin-right: auto" data-block-type="Text">project about solving "dinning philosopher problem"</blockquote><h2 class="u-text u-text-default u-block-control u-align-center u-subtitle u-block-f300-10" data-block="31" style="font-size: 1.75rem; margin-top: 1px; margin-left: auto; margin-right: auto; margin-bottom: 0px" data-block-type="Text">Problem statment</h2><ul class="u-text u-text-default u-block-control u-block-f300-11" data-block="32" style="margin-top: 5px; margin-left: 0px; margin-right: 0px; margin-bottom: 0px" data-block-type="Text"><li data-block-type=""><div class="u-list-icon hidden u-block-f300-12" style=""></div>​One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.</li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-13" style=""></div><div class="u-list-icon hidden u-block-f300-14" style=""></div>​​The philosophers alternatively <span style="font-weight: 700;">eat</span>, <span style="font-weight: 700;">think</span>, or <span style="font-weight: 700;">sleep</span>.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.</li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-15" style=""></div><div class="u-list-icon hidden u-block-f300-16" style=""></div>​There are also forks on the table. There are as many forks as philosophers.</li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-17" style=""></div>&nbsp;Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.&nbsp;<br></li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-18" style=""></div>When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.<br></li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-19" style=""></div>Every philosopher needs to eat and should never starve.<br></li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-20" style=""></div>Philosophers don’t speak with each other.<br></li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-21" style=""></div>Philosophers don’t know if another philosopher is about to die.<br></li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-22" style=""></div>No need to say that philosophers should avoid dying!&nbsp;<br></li></ul><p class="u-text u-text-default u-large-text u-text-variant u-block-control u-block-f300-23" data-block="34" style="font-size: 1.125rem; margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 0px" data-block-type="Text">​The simulation of the life of philosophers will be carried out according to the following rules:</p><ul class="u-text u-text-default u-block-control u-block-f300-24" data-block="35" style="margin-top: 4.75px; margin-right: auto; margin-bottom: 0px; margin-left: 0px" data-block-type="Text"><li data-block-type=""><div class="u-list-icon hidden u-block-f300-25" style=""></div>Program will take arguments:</li></ul><ol class="u-text u-text-default u-block-control u-block-f300-26" data-block="36" style="margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 45px" data-block-type="Text"><li data-block-type=""><span style="font-weight: 700;">​number_of_philosophers</span>: The number of philosophers and also the number
of forks.
</li><li><span style="font-weight: 700;">​time_to_die</span> (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
</li><li>​<span style="font-weight: 700;">time_to_eat</span> (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
</li><li><span style="font-weight: 700;">time_to_sleep</span> (in milliseconds): The time a philosopher will spend sleeping<br></li><li><span style="font-weight: 700;">number_of_times_each_philosopher_must_eat</span> (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.&nbsp;<br></li></ol><p class="u-text u-text-default u-small-text u-text-variant u-block-control u-block-f300-30" data-block="39" style="margin-top: -5px; margin-right: auto; margin-bottom: 0px; margin-left: 0px" data-block-type="Text">&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</p><ul class="u-text u-text-default u-block-control u-block-f300-27" data-block="37" style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px" data-block-type="Text"><li data-block-type="">Each philosopher has a number ranging from 1 to<span style="background-color: var(--bg-color); color: var(--bg-contrast); font-family: var(--text-font); font-size: 1rem; font-weight: 700; font-style: italic;"> <span style="font-weight: 400;">number_of_philosophers</span></span><span style="background-color: var(--bg-color); color: var(--bg-contrast); font-family: var(--text-font); font-size: 1rem;">.</span><br></li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-29" style=""></div>​Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.</li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-31" style=""></div>Each philosopher is a <span style="text-decoration: underline !important; font-style: italic;">thread</span>.</li><li data-block-type=""><div class="u-list-icon hidden u-block-f300-32" style=""></div>Each fork is a <span style="text-decoration: underline !important; font-style: italic;">mutex</span>.</li></ul><p class="u-text u-text-default u-block-control u-large-text u-text-variant u-block-f300-3" data-block="14" style="font-size: 1.125rem; margin-top: 4px; margin-right: auto; margin-bottom: 0px; margin-left: 0px" data-block-type="Text">​The spe​cific rules ​for ​the bonus part are:
</p><ul class="u-text u-text-default u-block-control u-block-f300-4" data-block="27" style="margin-top: 0px; margin-right: auto; margin-bottom: -0.25px; margin-left: 0px" data-block-type="Text"><li data-block-type=""><div class="u-list-icon hidden u-block-f300-5" style=""></div>​All the forks are put in the middle of the table. That means that any philosopher can take any fork to eat.</li><li><div class="u-list-icon hidden u-block-f300-6" style=""></div>​ They have no states in memory but the number of available forks is represented by
a <span style="text-decoration: underline !important; font-style: italic;">semaphore</span>.</li><li><div class="u-list-icon hidden u-block-f300-7" style=""></div>​Each philosopher should be a <span style="font-style: italic; text-decoration: underline !important;">process</span>. But the main process should not be a
philosopher.
</li></ul></div>
<style data-mode="XL" data-visited="true">@media (max-width: 0px) { .u-block-f300-2 {min-height: 800px}
.u-block-f300-8 {font-size: 3rem; margin-top: 0px; margin-bottom: 0px; margin-left: auto; margin-right: auto}
.u-block-f300-9 {margin-top: 0px; margin-bottom: 0px; margin-left: auto; margin-right: auto}
.u-block-f300-10 {font-size: 1.75rem; margin-top: 1px; margin-left: auto; margin-right: auto; margin-bottom: 0px}
.u-block-f300-11 {margin-top: 5px; margin-left: 0px; margin-right: 0px; margin-bottom: 0px}
.u-block-f300-23 {font-size: 1.125rem; margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-24 {margin-top: 4.75px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-26 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 45px}
.u-block-f300-30 {margin-top: -5px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-27 {margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px}
.u-block-f300-3 {font-size: 1.125rem; margin-top: 4px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-4 {margin-top: 0px; margin-right: auto; margin-bottom: -0.25px; margin-left: 0px} }</style><style data-mode="LG">@media (max-width: 0px) { .u-block-f300-2 {min-height: 800px}
.u-block-f300-8 {margin-top: 0px; margin-bottom: 0px; margin-left: auto; margin-right: auto; font-size: 3rem}
.u-block-f300-9 {margin-top: 0px; margin-bottom: 0px; margin-left: auto; margin-right: auto}
.u-block-f300-10 {margin-top: 1px; margin-left: auto; margin-right: auto; margin-bottom: 0px; font-size: 1.75rem}
.u-block-f300-11 {margin-top: 5px; margin-left: 0px; margin-right: 0px; margin-bottom: 0px}
.u-block-f300-23 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 0px; font-size: 1.125rem}
.u-block-f300-24 {margin-top: 4.75px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-26 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 45px}
.u-block-f300-30 {margin-top: -5px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-27 {margin-top: 0px; margin-left: 0px; margin-right: 0px; margin-bottom: 0px}
.u-block-f300-3 {margin-bottom: 0px; margin-top: 4px; font-size: 1.125rem; margin-right: auto; margin-left: 0px}
.u-block-f300-4 {margin-left: 0px; margin-right: auto; margin-bottom: -0.25px; margin-top: 0px} }</style><style data-mode="MD">@media (max-width: 0px) { .u-block-f300-2 {min-height: 800px}
.u-block-f300-8 {margin-top: 0px; margin-right: auto; margin-bottom: 0px; margin-left: auto; font-size: 3rem}
.u-block-f300-9 {margin-top: 0px; margin-right: auto; margin-bottom: 0px; margin-left: auto}
.u-block-f300-10 {margin-top: 1px; margin-right: auto; margin-bottom: 0px; margin-left: auto; font-size: 1.75rem}
.u-block-f300-11 {margin-top: 5px; margin-right: 0px; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-23 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 0px; font-size: 1.125rem}
.u-block-f300-24 {margin-top: 4.75px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-26 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 45px}
.u-block-f300-30 {margin-top: -5px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-27 {margin-top: 0px; margin-left: 0px; margin-right: 0px; margin-bottom: 0px}
.u-block-f300-3 {margin-bottom: 0px; margin-top: 4px; font-size: 1.125rem; margin-right: auto; margin-left: 0px}
.u-block-f300-4 {margin-top: 0px; margin-left: 0px; margin-right: 0px; margin-bottom: -0.25px} }</style><style data-mode="SM">@media (max-width: 0px) { .u-block-f300-2 {min-height: 800px}
.u-block-f300-8 {margin-top: 60px; margin-right: auto; margin-bottom: 0px; margin-left: auto; font-size: 3rem}
.u-block-f300-9 {margin-top: 0px; margin-right: auto; margin-bottom: 0px; margin-left: auto}
.u-block-f300-10 {margin-top: 1px; margin-right: auto; margin-bottom: 0px; margin-left: auto; font-size: 1.75rem}
.u-block-f300-11 {margin-top: 5px; margin-right: 0px; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-23 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 0px; font-size: 1.125rem}
.u-block-f300-24 {margin-top: 4.75px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-26 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 45px}
.u-block-f300-30 {margin-top: -5px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-27 {margin-top: 0px; margin-left: 0px; margin-right: 0px; margin-bottom: 0px}
.u-block-f300-3 {margin-bottom: 0px; margin-top: 4px; font-size: 1.125rem; margin-right: auto; margin-left: 0px}
.u-block-f300-4 {margin-top: 0px; margin-left: 0px; margin-right: 0px; margin-bottom: 60px} }</style><style data-mode="XS" data-visited="true">@media (max-width: 0px) { .u-block-f300-2 {min-height: 800px}
.u-block-f300-8 {margin-top: 60px; margin-right: auto; margin-bottom: 0px; margin-left: auto; font-size: 3rem}
.u-block-f300-9 {margin-top: 0px; margin-right: auto; margin-bottom: 0px; margin-left: auto}
.u-block-f300-10 {margin-top: 1px; margin-right: auto; margin-bottom: 0px; margin-left: auto; font-size: 1.5rem}
.u-block-f300-11 {margin-top: 5px; margin-right: 0px; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-23 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 0px; font-size: 1.125rem}
.u-block-f300-24 {margin-top: 4.75px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-26 {margin-top: 6px; margin-right: auto; margin-bottom: 0px; margin-left: 45px}
.u-block-f300-30 {margin-top: -5px; margin-right: auto; margin-bottom: 0px; margin-left: 0px}
.u-block-f300-27 {margin-top: 0px; margin-left: 0px; margin-right: 0px; margin-bottom: 0px}
.u-block-f300-3 {font-size: 1.125rem; margin-top: 4px; margin-bottom: 0px; margin-left: 0.5px; margin-right: 0.5px}
.u-block-f300-4 {margin-top: 0px; margin-left: 0px; margin-right: 0px; margin-bottom: 60px} }</style></section>

### There is some animation explanation:
![animation](assets/philo-animation.gif)
### Mandatory part using treads per philo and mutexes per fork
#### odd number of philosophers case
![m_odd_number_of_philo](assets/mandatoty%207%20800%20200%20200%205.png)
#### even number of philosophers case
![m_even_number_of_philo](assets/mandatory%208%20800%20200%20200%205.png)

### Bonus part using processes per philo and semaphore as forks
#### odd number of philosophers case
![b_even_number_of_philo](assets/bonus%207%20800%20200%20200%205.png)